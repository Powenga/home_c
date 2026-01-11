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

#endif