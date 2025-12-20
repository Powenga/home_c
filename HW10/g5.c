#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000 + 1

char changeSymbol(char a) {
    switch (a) {
        case 'a':
            return 'b';
        case 'A':
            return 'B';
        case 'b':
            return 'a';
        case 'B':
            return 'A';
        default:
            return a;
    }
}

int main(void) {
    FILE *inputFile, *outputFile;
    char word[SIZE];

    inputFile = fopen("input.txt", "r");    // read only
    outputFile = fopen("output.txt", "w");  // write only

    if (!inputFile) {
        printf("No file input.txt");
        return 0;
    }

    fscanf(inputFile, "%[^\n]", word);  // read both strings

    for (int i = 0; word[i] != '\0'; i++) {
        word[i] = changeSymbol(word[i]);
    }

    fprintf(outputFile, "%s", word);

    fclose(outputFile);
    fclose(inputFile);
    return 0;
}
