#ifndef CLI_H
#define CLI_H

#include <stdint.h>

enum Mode { MODE_YEAR, MODE_MONTH };

typedef struct {
    const char* input_file;
    int8_t month;  // -1 = year statistics
    uint8_t show_help;
} CliOptions;

int cli_parse(int argc, char* argv[], CliOptions* options);
void cli_print_usage(const char* prog);

#endif