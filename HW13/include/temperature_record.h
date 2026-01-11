#ifndef TEMPERATURE_RECORD_H
#define TEMPERATURE_RECORD_H
#include <stdint.h>

struct TemperatureRecord {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hours;
    uint8_t minutes;
    int8_t temperature;
    uint8_t valid;
};

typedef struct TemperatureRecord TemperatureRecord;

// Dynamic array
struct Records {
    TemperatureRecord* records;  // ptr to first elem of data
    uint16_t size;               // current size
    uint16_t capacity;  // max capacity: 65535, max size: 65535 * 8 ~ 512 КБ
};

typedef struct Records Records;

#endif