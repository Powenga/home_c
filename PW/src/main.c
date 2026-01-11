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
uint8_t show_help = 0;

uint8_t current_month = 0;
char* file_path = NULL;

Records data;

// Statistics
int8_t min;
int8_t max;
int8_t average;

void print_summary(int8_t* min, int8_t* max, int8_t* average) {
    printf("===========================================\n");
    printf("Max: %3dC; Min: %3dC; Average: %3dC.\n", *min, *max, *average);
}

void wait_for_key() {
    printf("\nPress any key to quit...\n");
    _getch();
}

int main(int argc, char* argv[]) {
    srand(time(NULL));

    // Generate random records
    if (!generate_temperature_records(&data, 350)) {
        printf("Generate records error.");
        wait_for_key();
        return 1;
    };

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
        print_help(argv[0]);
        wait_for_key();
        return 0;
    }

    if (!file_path) {
        printf("Please, provide path to file.\n");
        return 1;
    }

    // Month statistics
    if (mode == MONTH) {
        if (!get_month_min_temp(data.records, data.size, current_month, &min) ||
            !get_month_max_temp(data.records, data.size, current_month, &max) ||
            !get_month_average_temp(data.records, data.size, current_month,
                                    &average)) {
            printf("No data relates to the month: %d.\n", current_month);
            wait_for_key();
            return 0;
        }
        print_temperature_records_by_month(data.records, data.size,
                                           current_month);
        print_summary(&min, &max, &average);
        wait_for_key();
        return 0;
    }

    // Year statistics
    if (!get_year_min_temp(data.records, data.size, &min) ||
        !get_year_max_temp(data.records, data.size, &max) ||
        !get_year_average_temp(data.records, data.size, &average)) {
        printf("No data.\n");
        wait_for_key();
        return 0;
    }

    print_temperature_records(data.records, data.size);
    print_summary(&min, &max, &average);

    wait_for_key();
    return 0;
}
