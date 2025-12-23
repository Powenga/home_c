#include <stdio.h>

#include "../include/temp_api.h"
#include "../include/temperature_record.h"

#define MONTH_SIZE 31
#define YEAR_SIZE 365

temperature_record_t month[MONTH_SIZE];
temperature_record_t year[YEAR_SIZE];

int main(void) {
    printf("Sizeof s1 = %lu\n");
    return 0;
}
