#include "temp_functions.h"

#include <stdio.h>
#include <stdlib.h>

#include "temperature_record.h"
#include "utils.h"

uint8_t init_temperature_array(Records *data, uint16_t count) {
  data->capacity = count;
  data->size = 0;
  data->records = malloc((size_t)count * sizeof(TemperatureRecord));
  // Check memory allocation
  if (data->records == NULL) {
    data->capacity = 0;
    return 0;
  }
  return 1;
}

uint8_t add_record(Records *data, uint16_t year, uint8_t month, uint8_t day,
                   uint8_t hours, uint8_t minutes, int8_t temperature) {
  // If records is full
  if (data->capacity == data->size) {
    data->capacity = data->capacity * 2;
    data->records = realloc(data->records,
                            (size_t)data->capacity * sizeof(TemperatureRecord));
    // Check memory realloccation
    if (data->records == NULL) {
      data->capacity = data->capacity / 2;
      return 0;
    }
  }
  capacity new_elem_index = data->size;
  data->records[new_elem_index].year = year;
  data->records[new_elem_index].month = month;
  data->records[new_elem_index].day = day;
  data->records[new_elem_index].hours = hours;
  data->records[new_elem_index].minutes = minutes;
  data->records[new_elem_index].temperature = temperature;
  data->records[new_elem_index].valid = 1;
  data->size++;
  return 1;
}

static void init_temp_stats(Stats *stats) {
  stats->sum = 0;
  stats->count = 0;
  stats->initialized = 0;
}

static void update_temp_stats(Stats *stats, int8_t temperature) {
  if (!stats->initialized) {
    stats->min = temperature;
    stats->max = temperature;
    stats->initialized = 1;
  } else {
    if (temperature < stats->min)
      stats->min = temperature;
    if (temperature > stats->max)
      stats->max = temperature;
  }
  stats->sum += temperature;
  stats->count++;
}

void init_full_statistics(FullStatistics *full_stats) {
  full_stats->year_count = 0;
};

static YearStats *get_or_create_year(FullStatistics *full_stats,
                                     uint16_t year) {
  // Find existed year
  for (size_t i = 0; i < full_stats->year_count; i++) {
    if (full_stats->years[i].year == year) {
      return &full_stats->years[i];
    }
  }

  if (full_stats->year_count >= MAX_YEARS) {
    return NULL;
  }

  YearStats *new_year_stats = &full_stats->years[full_stats->year_count++];
  new_year_stats->year = year;

  // Init year stats
  init_temp_stats(&new_year_stats->year_stats);

  // Init every month stats
  for (int i = 0; i < 12; i++) {
    init_temp_stats(&new_year_stats->months[i]);
  }

  return new_year_stats;
}

// Main caclulate funtion with one cicle
int calculate_temperature_statistics(Records *data,
                                     FullStatistics *full_stats) {
  for (capacity i = 0; i < data->size; i++) {
    {
      TemperatureRecord *r = &data->records[i];

      YearStats *year = get_or_create_year(full_stats, r->year);
      if (!year) {
        return 0; // to many years
      }

      update_temp_stats(&year->year_stats, r->temperature);

      if (r->month >= 1 && r->month <= 12) {
        update_temp_stats(&year->months[r->month - 1], r->temperature);
      }
    }
  }
  return 1;
};

int8_t get_tempstats_average(Stats *stats) {
  return (stats->count == 0) ? 0 : (int8_t)(stats->sum / stats->count);
}

static void print_header() {
  printf("%-3s | %-5s | %-5s | %-7s | %-7s | %-7s\n", "#", "Year", "Month",
         "Min", "Max", "Avg");
}

static void print_row(uint16_t position, uint16_t year, uint8_t month,
                      int8_t min, int8_t max, int8_t average) {
  printf("%3d | %5d | %5d | %7d | %7d | %7d\n", position, year, month, min, max,
         average);
}

void print_month_statistics(uint16_t position, uint8_t month, int8_t min,
                            int8_t max, int8_t average) {
  printf("%3d | %5d | %7d | %7d | %7d\n", position, month, min, max, average);
}

static void print_year_statistics(int8_t min, int8_t max, int8_t average) {
  printf("Year statistics: Min %3dC; Max %3dC; Average %3dC.\n", min, max,
         average);
}

void print_all_stats(FullStatistics *stats) {
  for (uint8_t y = 0; y < stats->year_count; ++y) {
    YearStats *year = &stats->years[y];
    print_header();
    for (int m = 0; m < MONTHS_IN_YEAR; ++m) {
      Stats *stats = &year->months[m];
      if (stats->initialized == 0) {
        continue;
      }

      int8_t average = get_tempstats_average(stats);
      print_row(m + 1, year->year, m + 1, stats->min, stats->max, average);
    }
    Stats *year_stats = &year->year_stats;
    int8_t average = get_tempstats_average(year_stats);
    printf("--------------------------------------------------\n");
    print_year_statistics(year_stats->min, year_stats->max, average);
  }
}

void print_month_stats(FullStatistics *stats, uint8_t month) {
  if (month < 1 || month > 12) {
    return;
  }

  print_header();
  for (uint8_t y = 0; y < stats->year_count; ++y) {
    YearStats *year = &stats->years[y];
    Stats *stats = &year->months[month - 1];
    if (stats->count == 0) {
      continue;
    }

    int8_t average = get_tempstats_average(stats);

    print_row(1, year->year, month, stats->min, stats->max, average);
  }
}
