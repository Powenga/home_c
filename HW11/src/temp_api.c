#include <stdio.h>

#include "temperature_record.h"

int8_t get_month_average_temp(temperature_record_t year[], uint8_t size,
                              uint8_t month, uint8_t* p_average_temp) {
    int8_t result = 0;  // success boolean
    int8_t month_sum = 0;
    uint8_t month_count = 0;
    for (size_t i = 0; i < size; i++) {
        if (!year[i].valid) {
            continue;
        }
        // Sum and count if it's current month
        if (year[i].month == month) {
            month_sum += year[i].temperature;
            month_count++;
            result = 1;  // Some date is valid
        }
    }
    if (result) {
        *p_average_temp = month_sum / month_count;
    }
    return result;
}

int8_t get_month_min_temp(temperature_record_t year[], uint8_t size,
                          uint8_t month, int8_t* p_min_temp) {
    int8_t result = 0;  // success boolean
    // Find first
    for (size_t i = 0; i < size; i++) {
        // Skip not valid data or other month
        if (!year[i].valid || year[i].month != month) {
            continue;
        }
        int8_t current_temp = year[i].temperature;
        // First founded temp;
        if (!result) {
            *p_min_temp = current_temp;
            result = 1;
            // Other temps
        } else if (current_temp < *p_min_temp) {
            *p_min_temp = current_temp;
        }
    }
    return result;
};

int8_t get_month_max_temp(temperature_record_t* year, uint8_t size,
                          uint8_t month, int8_t* p_max_temp) {
    int8_t result = 0;  // success boolean
    // Find first
    for (size_t i = 0; i < size; i++) {
        // Skip not valid data or other month
        if (!year[i].valid || year[i].month != month) {
            continue;
        }
        int8_t current_temp = year[i].temperature;
        // First founded temp;
        if (!result) {
            *p_max_temp = current_temp;
            result = 1;
            // Other temps
        } else if (current_temp > *p_max_temp) {
            *p_max_temp = current_temp;
        }
    }
    return result;
};

int8_t get_year_average_temp(temperature_record_t year[], uint8_t size) {
    int8_t sum = 0;
    uint8_t count = 0;
    for (size_t i = 0; i < size; i++) {
        // Only for valid data
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
        // Skip not valid data
        if (!year[i].valid) {
            continue;
        }
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
        // Skip not valid days
        if (!year[i].valid) {
            continue;
        }
        int8_t current_temp = year[i].temperature;
        if (current_temp > max) {
            max = current_temp;
        }
    }
    return max;
};