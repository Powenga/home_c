#include <stdio.h>

void printDigits(int num) {
    if (num <= 0) {
        return;
    }
    printDigits(num / 10);
    printf("%d ", num % 10);
}

int main() {
    int input;
    scanf("%d", &input);
    if (input <= 0) {
        printf("Введите натуральное число!");
    }

    printDigits(input);
    return 0;
}