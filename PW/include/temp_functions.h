#ifndef TEMP_FUNCTIONS_H
#define TEMP_FUNCTIONS_H

#include <stdio.h>

#include "temperature_record.h"

#define MONTHS_IN_YEAR 12
#define MAX_YEARS 10

typedef struct {
    int8_t min;
    int8_t max;
    int64_t sum;
    int64_t count;
    int8_t initialized;
} Stats;

typedef struct {
    uint16_t year;
    Stats year_stats;
    Stats months[MONTHS_IN_YEAR];
} YearStats;

typedef struct {
    YearStats years[MAX_YEARS];
    uint8_t year_count;
} FullStatistics;

uint8_t init_temperature_array(Records* data, uint16_t count);
uint8_t add_record(Records* data, uint16_t year, uint8_t month, uint8_t day,
                   uint8_t hours, uint8_t minutes, int8_t temperature);

void init_full_statistics(FullStatistics* full_stats);
int calculate_temperature_statistics(Records* data, FullStatistics* full_stats);
void print_all_stats(FullStatistics* stats);
void print_month_stats(FullStatistics* stats, uint8_t month);

#endif