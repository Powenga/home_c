#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "temp_api.h"
#include "temperature_record.h"
#include "utils.h"

#define LINE_BUF_SIZE 256
#define DATA_SIZE 256
#define ROW_DATA_COUNT 6
#define MONTHS_COUNT 12

enum Mode { YEAR, MONTH };
enum Mode mode = YEAR;
// Array for monthes for statistics
uint8_t months[MONTHS_COUNT] = {0};
uint8_t show_help = 0;

char* file_path = NULL;

// Main storage
Records data;

void print_header() {
    printf("%-3s | %-5s | %-7s | %-7s | %-7s\n", "#", "Month", "Min", "Max",
           "Avg");
}

void print_month_statistics(uint16_t position, uint8_t month, int8_t min,
                            int8_t max, int8_t average) {
    printf("%3d | %5d | %7d | %7d | %7d\n", position, month, min, max, average);
}

void print_year_statistics(int8_t min, int8_t max, int8_t average) {
    printf("Year statistics: Min %3dC; Max %3dC; Average %3dC.\n", min, max,
           average);
}

void wait_for_key() {
    printf("\nPress any key to quit...\n");
    _getch();
}

int main(int argc, char* argv[]) {
    int result = 0;  // argument paramers
    opterr = 0;      // hide error message
    while ((result = getopt(argc, argv, "hf:m:")) != -1) {
        switch (result) {
            case 'h':
                show_help = 1;
                break;
            case 'f':
                file_path = optarg;
                break;
            case 'm':
                char* endptr;
                long value;
                value = strtol(optarg, &endptr, 10);

                if (*endptr != '\0' || value < 1 || value > 12) {
                    printf("Invalid month parameter: %s\n", optarg);
                    wait_for_key();
                    return 1;
                }
                mode = MONTH;
                months[(uint8_t)value - 1] = 1;
                break;
            case '?':
                printf("Unknown argument.\n");
                return 1;
            default:
                printf("Usage: %s -f path/to/file.csv -m 11.\n", argv[0]);
                return 1;
        }
    }

    // Help message
    if (show_help) {
        print_help(argv[0]);
        wait_for_key();
        return 0;
    }

    if (!file_path) {
        printf("Please, provide path to file.\n");
        return 1;
    }

    // Init main storage
    init_temperature_array(&data, DATA_SIZE);

    // Read file and store data
    FILE* file;
    file = fopen(file_path, "r");

    if (!file) {
        printf("Cant open file %s.", file_path);
        wait_for_key();
        return 1;
    }

    int year, month, day, hours, minutes, temperature;
    char line[LINE_BUF_SIZE];
    uint16_t line_number = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        line_number++;
        int row_data_count = sscanf(line, "%d;%d;%d;%d;%d;%d", &year, &month,
                                    &day, &hours, &minutes, &temperature);

        if (row_data_count != ROW_DATA_COUNT) {
            printf("Wrong format in line %d: %s", line_number, line);
            continue;
        }

        if (!validate_record(year, month, day, hours, minutes, temperature)) {
            printf("Invalid data in line %d: %s\n", line_number, line);
            continue;
        }

        // Add new record
        add_record(&data, (uint16_t)year, (uint8_t)month, (uint8_t)day,
                   (uint8_t)hours, (uint8_t)minutes, (uint8_t)temperature);
    }

    // close file
    fclose(file);

    // Statisctcs
    int8_t min;
    int8_t max;
    int8_t average;

    // Fill months if year mode
    if (mode == YEAR) {
        for (uint16_t i = 0; i < data.size; i++) {
            uint8_t month_index = data.records[i].month - 1;
            if (!months[month_index]) {
                months[month_index] = 1;
            }
        }
    }

    // Statistics
    printf("\n");
    print_header();

    for (size_t i = 0, position = 1; i < MONTHS_COUNT; i++) {
        if (!months[i]) {
            continue;
        }
        if (!get_month_min_temp(data.records, data.size, i + 1, &min) ||
            !get_month_max_temp(data.records, data.size, i + 1, &max) ||
            !get_month_average_temp(data.records, data.size, i + 1, &average)) {
            continue;
        }
        print_month_statistics(position, i + 1, min, max, average);
        position++;
    }

    if (mode == YEAR) {
        if (!get_year_min_temp(data.records, data.size, &min) ||
            !get_year_max_temp(data.records, data.size, &max) ||
            !get_year_average_temp(data.records, data.size, &average)) {
            printf("No data.\n");
            wait_for_key();
            return 0;
        }
        print_year_statistics(min, max, average);
    }

    wait_for_key();
    return 0;
}
