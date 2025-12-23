#include "temperature_record.h"

uint8_t date_to_int(temperature_record_t* record) {
    return record->year << 32 | record->month << 24 | record->day << 16 |
           record->hours << 8 | record->minutes;
}
