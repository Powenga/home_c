
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "cli.h"
#include "file_reader.h"
#include "temp_api.h"
#include "temperature_record.h"
#include "utils.h"

#define DATA_SIZE 256

#define MONTHS_COUNT 12

// Array for monthes for statistics
uint8_t months[MONTHS_COUNT] = {0};

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
    CliOptions options;
    if (!cli_parse(argc, argv, &options)) {
        cli_print_usage(argv[0]);
    }

    // Help message
    if (options.show_help) {
        print_help(argv[0]);
        return 0;
    }

    if (!options.input_file) {
        printf("Please, provide path to file.\n");
        return 1;
    }

    // Init main storage
    init_temperature_array(&data, DATA_SIZE);

    // Read file and store data
    FILE* file;
    file = fopen(options.input_file, "r");

    if (!file) {
        printf("Can't open file %s.\n", options.input_file);
        return 1;
    }

    // load data from file
    load_records_from_csv(file, &data);

    // Statisctcs
    int8_t min;
    int8_t max;
    int8_t average;

    // Fill months if year mode
    if (options.month == -1) {
        for (capacity i = 0; i < data.size; i++) {
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

    if (options.month == -1) {
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
