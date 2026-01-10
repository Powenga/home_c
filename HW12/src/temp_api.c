#include <stdio.h>

#include "temperature_record.h"

int8_t get_month_average_temp(temperature_record_t year[], uint8_t size,
                              uint8_t month, int8_t* p_average_temp) {
    int8_t result = 0;  // true if valid data exists
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
            result = 1;  // Some data is valid
        }
    }
    if (result) {
        *p_average_temp = month_sum / month_count;
    }
    return result;
}

int8_t get_month_min_temp(temperature_record_t year[], uint8_t size,
                          uint8_t month, int8_t* p_min_temp) {
    int8_t result = 0;  // true if valid data exists in month
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
    int8_t result = 0;  // true if valid data exists in month
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

int8_t get_year_average_temp(temperature_record_t year[], uint8_t size,
                             int8_t* p_average_temp) {
    int8_t result = 0;  // true if valid data exists in year
    int8_t sum = 0;
    uint8_t count = 0;
    for (size_t i = 0; i < size; i++) {
        if (!year[i].valid) {
            continue;
        }

        sum += year[i].temperature;
        count++;
        result = 1;
    }
    if (result) {
        *p_average_temp = sum / count;
    }
    return result;
};

int8_t get_year_min_temp(temperature_record_t year[], uint8_t size,
                         int8_t* p_min_temp) {
    int8_t result = 0;  // true if valid data exists in year
    for (size_t i = 0; i < size; i++) {
        // Skip not valid data
        if (!year[i].valid) {
            continue;
        }

        int8_t current_temp = year[i].temperature;
        if (!result) {
            *p_min_temp = current_temp;
            result = 1;
        } else if (current_temp < *p_min_temp) {
            *p_min_temp = current_temp;
        }
    }

    return result;
};

int8_t get_year_max_temp(temperature_record_t year[], uint8_t size,
                         int8_t* p_max_temp) {
    int8_t result = 0;  // true if valid data exists in year
    for (size_t i = 0; i < size; i++) {
        // Skip not valid data
        if (!year[i].valid) {
            continue;
        }

        int8_t current_temp = year[i].temperature;
        if (!result) {
            *p_max_temp = current_temp;
            result = 1;
        } else if (current_temp > *p_max_temp) {
            *p_max_temp = current_temp;
        }
    }

    return result;
};