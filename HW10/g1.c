#include <stdio.h>
#include <string.h>

#define SIZE 100

int main(void) {
    FILE *inputFile, *outputFile;
    char input[SIZE];
    inputFile = fopen("input.txt", "r");    // read only
    outputFile = fopen("output.txt", "w");  // write only
    if (!inputFile) {
        printf("No file input.txt");
        return 0;
    }

    fscanf(inputFile, "%[^\n]", input);  // read first string

    fprintf(outputFile, "%s, ", input);
    fprintf(outputFile, "%s, ", input);
    fprintf(outputFile, "%s ", input);
    fprintf(outputFile, "%d", strlen(input));

    fclose(inputFile);
    return 0;
}
