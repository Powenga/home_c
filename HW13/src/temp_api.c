#include <stdio.h>
#include <stdlib.h>

#include "temperature_record.h"
#include "utils.h"

int8_t get_month_average_temp(TemperatureRecord* records, uint16_t size,
                              uint8_t month, int8_t* p_average_temp) {
    int8_t result = 0;  // true if valid data exists
    int16_t month_sum = 0;
    uint8_t month_count = 0;
    for (uint16_t i = 0; i < size; i++) {
        if (!records[i].valid) {
            continue;
        }
        // Sum and count if it's current month
        if (records[i].month == month) {
            month_sum += records[i].temperature;
            month_count++;
            result = 1;  // Some data is valid
        }
    }
    if (result) {
        *p_average_temp = month_sum / month_count;
    }
    return result;
}

int8_t get_month_min_temp(TemperatureRecord* records, uint16_t size,
                          uint8_t month, int8_t* p_min_temp) {
    int8_t result = 0;  // true if valid data exists in month
    // Find first
    for (uint16_t i = 0; i < size; i++) {
        // Skip not valid data or other month
        if (!records[i].valid || records[i].month != month) {
            continue;
        }
        int8_t current_temp = records[i].temperature;
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

int8_t get_month_max_temp(TemperatureRecord* records, uint16_t size,
                          uint8_t month, int8_t* p_max_temp) {
    int8_t result = 0;  // true if valid data exists in month
    // Find first
    for (uint16_t i = 0; i < size; i++) {
        // Skip not valid data or other month
        if (!records[i].valid || records[i].month != month) {
            continue;
        }
        int8_t current_temp = records[i].temperature;
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

int8_t get_year_average_temp(TemperatureRecord* records, uint16_t size,
                             int8_t* p_average_temp) {
    int8_t result = 0;  // true if valid data exists in year
    int16_t sum = 0;
    uint8_t count = 0;
    for (size_t i = 0; i < size; i++) {
        if (!records[i].valid) {
            continue;
        }

        sum += records[i].temperature;
        count++;
        result = 1;
    }
    if (result) {
        *p_average_temp = sum / count;
    }
    return result;
};

int8_t get_year_min_temp(TemperatureRecord* records, uint16_t size,
                         int8_t* p_min_temp) {
    int8_t result = 0;  // true if valid data exists in year
    for (size_t i = 0; i < size; i++) {
        // Skip not valid data
        if (!records[i].valid) {
            continue;
        }

        int8_t current_temp = records[i].temperature;
        if (!result) {
            *p_min_temp = current_temp;
            result = 1;
        } else if (current_temp < *p_min_temp) {
            *p_min_temp = current_temp;
        }
    }

    return result;
};

int8_t get_year_max_temp(TemperatureRecord* records, uint16_t size,
                         int8_t* p_max_temp) {
    int8_t result = 0;  // true if valid data exists in year
    for (size_t i = 0; i < size; i++) {
        // Skip not valid data
        if (!records[i].valid) {
            continue;
        }

        int8_t current_temp = records[i].temperature;
        if (!result) {
            *p_max_temp = current_temp;
            result = 1;
        } else if (current_temp > *p_max_temp) {
            *p_max_temp = current_temp;
        }
    }

    return result;
};

uint8_t add_record(TemperatureRecord* records, uint16_t position, uint16_t year,
                   uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes,
                   int8_t temperature) {
    uint8_t valid =
        validate_record(year, month, day, hours, minutes, temperature);
    if (!valid) {
        return 0;
    }
    records[position].year = year;
    records[position].month = month;
    records[position].day = day;
    records[position].hours = hours;
    records[position].minutes = minutes;
    records[position].temperature = temperature;
    records[position].valid = valid;
    return 1;
}

int8_t remove_record(TemperatureRecord* records, uint16_t* size,
                     uint16_t index) {
    if (index >= *size) {
        return 0;
    }

    for (uint16_t i = index; i < *size - 1; i++) {
        records[i] = records[i + 1];
    }
    (*size)--;
    return 1;
}

uint16_t create_temperature_records(TemperatureRecord* records, uint16_t size) {
    uint16_t year = 1970;
    uint8_t month = 1;
    uint8_t day = 1;
    uint8_t hours = 0;
    uint8_t minutes = 1;
    for (uint16_t i = 0; i < size; i++) {
        int8_t temperature = (int8_t)(rand() % 201 - 100);  // [-100; 100]
        add_record(records, i, year, month, day, hours, minutes, temperature);
        increment_day(&year, &month, &day);
    }
    return size;
}

static void sort_temperature_records_by_date(TemperatureRecord* records,
                                             uint16_t size) {
    qsort(records, size, sizeof(TemperatureRecord),
          temp_record_comparator_by_date);
}

static void print_record(TemperatureRecord* record,
                         uint16_t increment_position) {
    printf("%03d. %04d-%02d-%02dT%02d:%02d t=%3d\n", increment_position,
           record->year, record->month, record->day, record->hours,
           record->minutes, record->temperature);
};

void print_temperature_records(TemperatureRecord* records, uint16_t size) {
    sort_temperature_records_by_date(records, size);
    uint16_t increment_position = 1;
    for (uint16_t i = 0; i < size; i++) {
        if (!records[i].valid) {
            continue;
        }
        print_record(&records[i], increment_position++);
    }
}

void print_temperature_records_by_month(TemperatureRecord* records,
                                        uint16_t size, uint8_t month) {
    sort_temperature_records_by_date(records, size);
    uint16_t increment_position = 1;
    for (uint16_t i = 0; i < size; i++) {
        if (!records[i].valid || records[i].month != month) {
            continue;
        }
        print_record(&records[i], increment_position++);
    }
}
