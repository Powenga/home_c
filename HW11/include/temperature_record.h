#include <stdint.h>

struct temperature_record {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hours;
    uint8_t minutes;
    int8_t temperature;
};

typedef struct temperature_record temperature_record_t;