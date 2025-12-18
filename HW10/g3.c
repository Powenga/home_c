#include <stdio.h>
#include <string.h>

#define SIZE 1000

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

    int length = strlen(input);
    char lastSymbol = input[length - 1];

    for (int i = 0; i < length - 1; i++) {
        if (lastSymbol == input[i]) {
            fprintf(outputFile, "%d ", i);
        }
    }

    fclose(inputFile);
    return 0;
}
