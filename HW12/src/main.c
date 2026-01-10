#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "temp_api.h"
#include "temperature_record.h"

#define YEAR_SIZE 365

enum Mode { YEAR, MONTH };

temperature_record_t year[YEAR_SIZE];

enum Mode mode = YEAR;
uint8_t current_month = 0;
char* file_path;

int main(int argc, char* argv[]) {
    int result = 0;  // argument paramers
    opterr = 0;      // hide error message
    while ((result = getopt(argc, argv, "hf:m:")) != -1) {
        switch (result) {
            case 'h':
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
                    return 1;
                }

                current_month = (uint8_t)value;
                break;
            case '?':
                printf("Unknown argument \n");
                break;
            default:
                printf("Usage: %s -f path/to/file.csv -m 11.\n", argv[0]);
                break;
        }
    }

    printf("\nPress any key to quit...\n");
    _getch();
    return 0;
}
