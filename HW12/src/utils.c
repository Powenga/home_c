#include <stdlib.h>

#include "temperature_record.h"

uint64_t date_to_int(temperature_record_t* record) {
    return (uint64_t)record->year << 32 | (uint64_t)record->month << 24 |
           (uint64_t)record->day << 16 | (uint64_t)record->hours << 8 |
           (uint64_t)record->minutes;
}

static uint8_t is_leap_year(uint16_t year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static uint8_t days_in_month(uint16_t year, uint8_t month) {
    static const uint8_t days[] = {31, 28, 31, 30, 31, 30,
                                   31, 31, 30, 31, 30, 31};

    if (month == 2) return days[1] + is_leap_year(year);

    return days[month - 1];
}

static uint8_t validate_record(uint16_t year, uint8_t month, uint8_t day,
                               uint8_t hours, uint8_t minutes,
                               int8_t temperature) {
    if (year < 1970 || year > 2100) return 0;

    if (month < 1 || month > 12) return 0;

    if (day < 1 || day > days_in_month(year, month)) return 0;

    if (hours > 23) return 0;

    if (minutes > 59) return 0;

    if (temperature < -100 || temperature > 100) return 0;
}

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

    for (uint16_t i = index; i < -*count - 1; i++) {
        data[i] = data[i + 1];
    }
    (*count)--;
    return 1;
}

static void increment_minute(uint16_t* year, uint8_t* month, uint8_t* day,
                             uint8_t* hours, uint8_t* minutes) {
    (*minutes)++;

    if (*minutes < 60) return;

    *minutes = 0;
    (*hours)++;

    if (*hours < 24) return;

    *hours = 0;
    (*day)++;

    if (*day <= days_in_month(*year, *month)) return;

    *day = 1;
    (*month)++;

    if (*month <= 12) return;

    *month = 1;
    (*year)++;
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
