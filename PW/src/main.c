
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "cli.h"
#include "file_reader.h"
#include "temp_functions.h"
#include "temperature_record.h"
#include "utils.h"

#define DATA_SIZE 256

int main(int argc, char *argv[]) {
  CliOptions options;
  if (!parse_cli(argc, argv, &options)) {
    print_cli_usage(argv[0]);
    return 0;
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

  // Init records store
  Records data;
  init_temperature_array(&data, DATA_SIZE);

  // Read file and put record
  FILE *file;
  file = fopen(options.input_file, "r");

  if (!file) {
    printf("Can't open file %s.\n", options.input_file);
    return 1;
  }

  // load data from file
  load_records_from_csv(file, &data);

  // Statisctcs
  printf("\n");
  FullStatistics full_statistics;
  init_full_statistics(&full_statistics);

  calculate_temperature_statistics(&data, &full_statistics);

  if (options.month == -1) {
    print_all_stats(&full_statistics);
  } else {
    print_month_stats(&full_statistics, options.month);
  }
  printf("\n");

  return 0;
}
