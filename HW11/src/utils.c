#include "temperature_record.h"

uint64_t date_to_int(temperature_record_t* record) {
    return (uint64_t)record->year << 32 | (uint64_t)record->month << 24 |
           (uint64_t)record->day << 16 | (uint64_t)record->hours << 8 |
           (uint64_t)record->minutes;
}