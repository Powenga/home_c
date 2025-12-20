#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100 + 1

int getCountCharInWord(char* word, char c) {
    int count = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] == c) {
            count++;
        }
    }
    return count;
}

int isAlreadyAdded(char* result, char c) {
    for (int i = 0; result[i] != '\0'; i++) {
        if (result[i] == c) {
            return 1;
        }
    }
    return 0;
}

int compareChars(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

int main(void) {
    FILE *inputFile, *outputFile;
    char word1[SIZE], word2[SIZE];
    char symbols[SIZE];
    int index = 0;

    inputFile = fopen("input.txt", "r");    // read only
    outputFile = fopen("output.txt", "w");  // write only

    if (!inputFile) {
        printf("No file input.txt");
        return 0;
    }

    fscanf(inputFile, "%s %s", word1, word2);  // read both strings

    char result[SIZE] = "";
    int result_index = 0;

    for (int i = 0; word1[i] != '\0'; i++) {
        char c = word1[i];

        // if sumbol exists ones in word 1
        if (getCountCharInWord(word1, c) == 1) {
            // if sumbol exists ones in word 2
            if (getCountCharInWord(word2, c) == 1) {
                // And there isn't already in result
                if (!isAlreadyAdded(result, c)) {
                    result[result_index++] = c;
                    result[result_index] = '\0';  // move line end
                }
            }
        }
    }

    // Sort result
    qsort(result, strlen(result), sizeof(char), compareChars);

    if (result[0] != '\0') {
        for (int i = 0; result[i] != '\0'; i++) {
            fprintf(outputFile, "%c ", result[i]);
        }
    }

    fclose(outputFile);
    fclose(inputFile);
    return 0;
}
