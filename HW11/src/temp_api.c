#include <stdio.h>

#include "temperature_record.h"

int8_t get_month_average_temp(temperature_record_t year[], uint8_t size,
                              uint8_t month) {
    int8_t month_sum = 0;
    uint8_t month_count = 0;
    for (size_t i = 0; i < size; i++) {
        if (year[i].month == month) {
            month_sum += year[i].temperature;
            month_count++;
        }
    }
    return month_sum / month_count;
}

int8_t get_month_min_temp(temperature_record_t* year, uint8_t month) {};
int8_t get_month_max_temp(temperature_record_t* year, uint8_t month) {};

int8_t get_year_average_temp(temperature_record_t year[], uint8_t size) {
    int8_t sum = 0;
    uint8_t count = 0;
    for (size_t i = 0; i < size; i++) {
        if (year[i].valid) {
            sum += year[i].temperature;
            count++;
        }
    }
    return sum / count;
};

int8_t get_year_min_temp(temperature_record_t year[], uint8_t size) {
    int8_t min = year[0].temperature;
    for (size_t i = 1; i < size; i++) {
        int8_t current_temp = year[i].temperature;
        if (current_temp < min) {
            min = current_temp;
        }
    }
    return min;
};

int8_t get_year_max_temp(temperature_record_t year[], uint8_t size) {
    int8_t max = year[0].temperature;
    for (size_t i = 1; i < size; i++) {
        int8_t current_temp = year[i].temperature;
        if (current_temp > max) {
            max = current_temp;
        }
    }
    return max;
};