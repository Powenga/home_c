#ifndef TEMP_API_H
#define TEMP_API_H

#include <stdio.h>

#include "temperature_record.h"

int8_t get_month_average_temp(temperature_record_t* year, uint8_t month);
int8_t get_month_min_temp(temperature_record_t* year, uint8_t month);
int8_t get_month_max_temp(temperature_record_t* year, uint8_t month);
int8_t get_year_average_temp(temperature_record_t* year);
int8_t get_year_min_temp(temperature_record_t* year);
int8_t get_year_max_temp(temperature_record_t* year);
void add_record(temperature_record_t* data, uint16_t position, uint16_t year,
                uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes,
                int8_t temperature);
void remove_record(temperature_record_t* data, uint16_t* count, uint16_t index);
void create_temperature_records(temperature_record_t* data, int16_t count);

#endif