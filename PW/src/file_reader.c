#include <stdio.h>

#include "temp_api.h"
#include "temperature_record.h"
#include "utils.h"

#define LINE_BUF_SIZE 256
#define ROW_DATA_COUNT 6

void load_records_from_csv(FILE* input_file, Records* ptr_data) {
    int year, month, day, hours, minutes, temperature;
    char line[LINE_BUF_SIZE];
    uint16_t line_number = 0;

    while (fgets(line, sizeof(line), input_file) != NULL) {
        line_number++;
        int row_data_count = sscanf(line, "%d;%d;%d;%d;%d;%d", &year, &month,
                                    &day, &hours, &minutes, &temperature);

        if (row_data_count != ROW_DATA_COUNT) {
            printf("Wrong format in line %d: %s\n", line_number, line);
            continue;
        }

        if (!validate_record(year, month, day, hours, minutes, temperature)) {
            printf("Invalid data in line %d: %s\n", line_number, line);
            continue;
        }

        // Add new record
        add_record(ptr_data, (uint16_t)year, (uint8_t)month, (uint8_t)day,
                   (uint8_t)hours, (uint8_t)minutes, (uint8_t)temperature);
    }

    // close file
    fclose(input_file);
}