#include <stdio.h>
#include <stdlib.h>

#include "temperature_record.h"
#include "utils.h"

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

uint8_t add_record(temperature_record_t* data, uint16_t position, uint16_t year,
                   uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes,
                   int8_t temperature) {
    uint8_t valid =
        validate_record(year, month, day, hours, minutes, temperature);
    if (!valid) {
        return 0;
    }
    data[position].year = year;
    data[position].month = month;
    data[position].day = day;
    data[position].hours = hours;
    data[position].minutes = minutes;
    data[position].temperature = temperature;
    data[position].valid = valid;
    return 1;
}

int8_t remove_record(temperature_record_t* data, uint16_t* count,
                     uint16_t index) {
    if (index >= *count) {
        return 0;
    }

    for (uint16_t i = index; i < *count - 1; i++) {
        data[i] = data[i + 1];
    }
    (*count)--;
    return 1;
}

uint16_t create_temperature_records(temperature_record_t* data, int16_t count) {
    uint16_t year = 1970;
    uint8_t month = 1;
    uint8_t day = 1;
    uint8_t hours = 0;
    uint8_t minutes = 1;
    for (int16_t i = 0; i < count; i++) {
        int8_t temperature = (int8_t)(rand() % 201 - 100);  // [-100; 100]
        add_record(data, i, year, month, day, hours, minutes, temperature);
        increment_minute(&year, &month, &day, &hours, &minutes);
    }
    return count;
}

void print_temperature_records(temperature_record_t* data, int16_t count) {
    for (int16_t i = 0; i < count; i++) {
        if (!data[i].valid) {
            continue;
        }
        printf("%04d-%02d-%02dT%02d:%02d t=%3d", data[i].year, data[i].month,
               data[i].day, data[i].hours, data[i].minutes,
               data[i].temperature);
    }
}