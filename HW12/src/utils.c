#include "temperature_record.h"

uint64_t date_to_int(temperature_record_t* record) {
    return (uint64_t)record->year << 32 | (uint64_t)record->month << 24 |
           (uint64_t)record->day << 16 | (uint64_t)record->hours << 8 |
           (uint64_t)record->minutes;
}

void add_record(temperature_record_t* data, uint16_t position, uint16_t year,
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

static uint8_t is_leap_year(uint16_t year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static uint8_t days_in_month(uint16_t year, uint8_t month) {
    static const uint8_t days[] = {31, 28, 31, 30, 31, 30,
                                   31, 31, 30, 31, 30, 31};

    if (month == 2) return days[1] + is_leap_year(year);

    return days[month - 1];
}

uint8_t validate_record(uint16_t year, uint8_t month, uint8_t day,
                        uint8_t hours, uint8_t minutes, int8_t temperature) {
    if (year < 1970 || year > 2100) return 0;

    if (month < 1 || month > 12) return 0;

    if (day < 1 || day > days_in_month(year, month)) return 0;

    if (hours > 23) return 0;

    if (minutes > 59) return 0;

    if (temperature < -100 || temperature > 100) return 0;
}