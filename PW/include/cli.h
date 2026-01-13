#ifndef CLI_H
#define CLI_H

#include <stdint.h>

enum Mode { MODE_YEAR, MODE_MONTH };

typedef struct {
    const char* input_file;
    int8_t month;  // -1 = year statistics
    uint8_t show_help;
} CliOptions;

int parse_cli(int argc, char* argv[], CliOptions* options);
void print_cli_usage(const char* prog);

#endif