#include "cli.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int parse_cli(int argc, char* argv[], CliOptions* options) {
    // Init options
    options->input_file = NULL;
    options->month = -1;
    options->show_help = 0;

    int result;  // arguments
    opterr = 0;  // hide error messsage

    while ((result = getopt(argc, argv, "hf:m:")) != -1) {
        switch (result) {
            case 'h':
                options->show_help = 1;
                break;
            case 'f':
                options->input_file = optarg;
                break;
            case 'm':
                char* endptr;
                long value;
                value = strtol(optarg, &endptr, 10);

                if (*endptr != '\0' || value < 1 || value > 12) {
                    return 0;
                }
                options->month = (uint8_t)value;
                break;
            case '?':
                return 0;
            default:
                return 0;
        }
    }
    return 1;
}

void print_cli_usage(const char* prog) {
    printf("Usage: %s -f <input_file> [-m <month 1..12>]\n", prog);
}
