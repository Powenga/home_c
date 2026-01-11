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
typedef uint32_t capacity;

// Dynamic array
struct Records {
    TemperatureRecord* records;  // ptr to first elem of data
    capacity size;               // current size
    capacity capacity;
};

typedef struct Records Records;

#endif