#include <stdio.h>
// This program generates a truth table to verify the logical equivalence
int table[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

int main(void) {
    printf("\nTruth Table for A<=B and !A||B\n");
    // Header for the truth table
    printf("|  A  |  B  | A<=B | !A||B | isEqual? |\n");
    printf("---------------------------------------\n");

    for (int i = 0; i < 4; i++) {
        printf("|  %d  |  %d  |  %d   |   %d   |     %d    |\n", table[i][0],
               table[i][1], table[i][0] <= table[i][1],
               !table[i][0] || table[i][1],
               (table[i][0] <= table[i][1]) == !table[i][0] || table[i][1]);
        printf("---------------------------------------\n");
    }

    printf("\nTruth Table for A==B and (A&&B)||(!A&&!B)\n");
    // Header for the truth table
    printf("|  A  |  B  | A==B | (A&&B)||(!A&&!B) | isEqual? |\n");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < 4; i++) {
        printf("|  %d  |  %d  |   %d  |         %d        |     %d    |\n",
               table[i][0], table[i][1], table[i][0] == table[i][1],
               (table[i][0] && table[i][1]) || (!table[i][0] && !table[i][1]),
               (table[i][0] == table[i][1]) == (table[i][0] && table[i][1]) ||
                   (!table[i][0] && !table[i][1]));
        printf("--------------------------------------------------\n");
    }

    return 0;
}
