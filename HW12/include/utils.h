#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

#include "temperature_record.h"

void add_record(temperature_record_t* data, uint16_t position, uint16_t year,
                uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes,
                int8_t temperature);

void remove_record(temperature_record_t* data, uint16_t* count, uint16_t index);

void create_temperature_records(temperature_record_t* data, int16_t count);

uint64_t date_to_int(temperature_record_t* record);

#endif