#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "temp_api.h"
#include "temperature_record.h"

#define SIZE 300

enum Mode { YEAR, MONTH };
enum Mode mode = YEAR;
uint8_t show_help = 0;

uint8_t current_month = 0;
char* file_path;

struct {
    uint16_t size;
    temperature_record_t records[SIZE];
} data;

int8_t min;
int8_t max;
int8_t average;

void print_summary(int8_t* min, int8_t* max, int8_t* average) {
    printf("Max: %3dC; Min: %3dC; Average: %3dC.\n", *min, *max, *average);
}

void wait_for_key() {
    printf("\nPress any key to quit...\n");
    _getch();
}

int main(int argc, char* argv[]) {
    srand(time(NULL));

    // Generate random records
    data.size = create_temperature_records(data.records, 75);

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

                if (*endptr != '\0' || value < 0 || value > 11) {
                    printf("Invalid month parameter: %s\n", optarg);
                    wait_for_key();
                    return 1;
                }
                mode = MONTH;
                current_month = (uint8_t)value;
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
        printf("Shows temperature statistics by year or month.\n");
        printf("Usage: %s -f path/to/file.csv -m 11.\n", argv[0]);
        printf("\t-h - Help text;  \n");
        printf(
            "\t-f path/to/file.csv - Specify file with temperature "
            "data;"
            "\n");
        printf(
            "\t-m month_number - Specify month number to show month "
            "statistics, 0 - January."
            "\n");
        wait_for_key();
        return 0;
    }

    // Month statistics
    if (mode == MONTH) {
        if (!get_month_min_temp(data.records, data.size, current_month, &min) ||
            !get_month_max_temp(data.records, data.size, current_month, &max) ||
            !get_month_average_temp(data.records, data.size, current_month,
                                    &average)) {
            printf("No data relates to the month.");
            wait_for_key();
            return 0;
        }
    }

    // Year statistics
    if (!get_year_min_temp(data.records, data.size, &min) ||
        !get_year_max_temp(data.records, data.size, &max) ||
        !get_year_average_temp(data.records, data.size, &average)) {
        printf("No data.");
        wait_for_key();
        return 0;
    }

    print_temperature_records(data.records, data.size);
    print_summary(&min, &max, &average);

    wait_for_key();
    return 0;
}
