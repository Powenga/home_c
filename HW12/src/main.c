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
                printf("Usage: app [options].\n");
                printf("-h - Help text;  \n");
                printf(
                    "-f path/to/file.csv - Specify file with temperature data;"
                    "\n");
                printf(
                    "-m month_number - Specify month number to show month "
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
                break;
        }
    }
    return 0;
}
