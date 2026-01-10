#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

#include "temperature_record.h"

uint64_t date_to_int(temperature_record_t* record);
uint8_t validate_record(uint16_t year, uint8_t month, uint8_t day,
                        uint8_t hours, uint8_t minutes, int8_t temperature);
void increment_minute(uint16_t* year, uint8_t* month, uint8_t* day,
                      uint8_t* hours, uint8_t* minutes);

#endif