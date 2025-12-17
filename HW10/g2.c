#include <stdio.h>
#define SIZE 100

int main(void) {
    FILE *inputFile, *outputFile;
    int number;
    int digits[] = {2, 4, 6, 8};

    inputFile = fopen("input.txt", "r");    // read only
    outputFile = fopen("output.txt", "w");  // write only
    if (!inputFile) {
        printf("No file input.txt");
        return 0;
    }

    fscanf(inputFile, "%d", &number);  // read first string

    if (number > 26) {
        printf("Number has to be lesser than 27!");
        return 0;
    }

    if (number % 2 != 0) {
        printf("Number has to be even!");
    }

    for (int i = 0; i < number; i++) {
        if (i % 2 == 0) {
            fprintf(outputFile, "%c", 'A' + i / 2);
        } else {
            fprintf(outputFile, "%d", digits[(i / 2) % 4]);
        }
    }

    fclose(inputFile);
    return 0;
}
