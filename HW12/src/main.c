#include <stdio.h>
#include <unistd.h>

#include "temp_api.h"
#include "temperature_record.h"

#define YEAR_SIZE 365

temperature_record_t year[YEAR_SIZE];

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
                    "statistics, 0 - january;"
                    "\n");
                break;
            case 'f':
                printf("Found file \"f = %s\"\n", optarg);
                break;
            case 'm':
                printf("Found month \"f = %s\"\n", optarg);
                break;
            case '?':
                printf("Unknown argument \n");
                break;
            default:
                printf("Usage: %s -f path/to/file.csv -m 11.\n", argv[0]);
                break;
        }
    }

    printf("\nPress q to quit...\n");
    while (fgetc(stdin) != 'q');
    return 0;
}
