#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "temp_api.h"
#include "temperature_record.h"
#include "utils.h"

enum Mode { YEAR, MONTH };
enum Mode mode = YEAR;
// Array for monthes for statistics
uint8_t months[12] = {0};
uint8_t month_count = 0;
uint8_t show_help = 0;

char* file_path = NULL;

// Main storage
Records data;

void print_header() {
    printf("%-3s | %-5s | %-7s | %-7s | %-7s\n", "№", "Month", "Avg", "Min",
           "Max");
}

void print_month_statistics(uint16_t position, uint8_t month, int8_t* min,
                            int8_t* max, int8_t* average) {
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
                months[0] = (uint8_t)value;
                month_count++;
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

    // Read file and store data

    // Statisctcs
    int8_t min;
    int8_t max;
    int8_t average;

    for (size_t i = 0; i < month_count; i++) {
        // Statistics

        if (!get_month_min_temp(data.records, data.size, months[i], &min) ||
            !get_month_max_temp(data.records, data.size, months[i], &max) ||
            !get_month_average_temp(data.records, data.size, months[i],
                                    &average)) {
            continue;
        }
        print_month_statistics(i + 1, months[i], min, max, average);
    }

    if (mode == YEAR) {
        if (!get_year_min_temp(data.records, data.size, &min) ||
            !get_year_max_temp(data.records, data.size, &max) ||
            !get_year_average_temp(data.records, data.size, &average)) {
            printf("No data.\n");
        }
        print_year_statistics(min, max, average);
    }

    wait_for_key();
    return 0;
}
