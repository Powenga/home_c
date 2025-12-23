#include <stdio.h>

#include "temperature_record.h"

int8_t get_month_average_temp(temperature_record_t* year, uint8_t month) {}
int8_t get_month_min_temp(temperature_record_t* year, uint8_t month) {};
int8_t get_month_max_temp(temperature_record_t* year, uint8_t month) {};

int8_t get_year_average_temp(temperature_record_t* year, uint8_t size) {
    uint8_t sum = 0;
    for (size_t i = 0; i < size; i++) {
        sum += year->temperature;
    }
    return sum / size;
};

int8_t get_year_min_temp(temperature_record_t* year) {};
int8_t get_year_max_temp(temperature_record_t* year) {};