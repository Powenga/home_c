#include "temperature_record.h"

static uint64_t date_to_uint64(TemperatureRecord* record) {
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

uint8_t validate_record(uint16_t year, uint8_t month, uint8_t day,
                        uint8_t hours, uint8_t minutes, int8_t temperature) {
    if (year < 1970 || year > 2100) return 0;

    if (month < 1 || month > 12) return 0;

    if (day < 1 || day > days_in_month(year, month)) return 0;

    if (hours > 23) return 0;

    if (minutes > 59) return 0;

    if (temperature < -100 || temperature > 100) return 0;
    return 1;
}

void increment_minute(uint16_t* year, uint8_t* month, uint8_t* day,
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

void increment_day(uint16_t* year, uint8_t* month, uint8_t* day) {
    (*day)++;

    if (*day <= days_in_month(*year, *month)) return;

    *day = 1;
    (*month)++;

    if (*month <= 12) return;

    *month = 1;
    (*year)++;
}

int temp_record_comparator_by_date(const void* a, const void* b) {
    TemperatureRecord* a_ptr = (TemperatureRecord*)a;
    TemperatureRecord* b_ptr = (TemperatureRecord*)b;
    uint64_t int_date_a = date_to_uint64(a_ptr);
    uint64_t int_date_b = date_to_uint64(b_ptr);
    if (int_date_a < int_date_b) {
        return -1;
    }
    if (int_date_a > int_date_b) {
        return -1;
    }
    return 0;
}
