#ifndef TEMP_API_H
#define TEMP_API_H

#include <stdio.h>

#include "temperature_record.h"

int8_t get_month_average_temp(temperature_record_t* records, uint16_t size,
                              uint8_t month, int8_t* p_average_temp);
int8_t get_month_min_temp(temperature_record_t* records, uint16_t size,
                          uint8_t month, int8_t* p_min_temp);
int8_t get_month_max_temp(temperature_record_t* records, uint16_t size,
                          uint8_t month, int8_t* p_max_temp);
int8_t get_year_average_temp(temperature_record_t* records, uint16_t size,
                             int8_t* p_average_temp);
int8_t get_year_min_temp(temperature_record_t* records, uint16_t size,
                         int8_t* p_min_temp);
int8_t get_year_max_temp(temperature_record_t* records, uint16_t size,
                         int8_t* p_max_temp);
int8_t add_record(temperature_record_t* records, uint16_t position,
                  uint16_t year, uint8_t month, uint8_t day, uint8_t hours,
                  uint8_t minutes, int8_t temperature);
int8_t remove_record(temperature_record_t* records, uint16_t* size,
                     uint16_t index);
uint16_t create_temperature_records(temperature_record_t* records,
                                    uint16_t size);
void print_temperature_records(temperature_record_t* records, uint16_t size);
void print_temperature_records_by_month(temperature_record_t* records,
                                        uint16_t size, uint8_t month);

#endif