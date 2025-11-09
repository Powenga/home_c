#include <stdio.h>

int main(void) {
    signed int input, result = 10;
    scanf("%d", &input);

    if (input <= 0) {
        printf("Введите натуральное число");
    }

    while (result <= input) {
        int sum = 0, multliplication = 1, temp = result;
        while (temp > 0) {
            sum += temp % 10;
            multliplication *= temp % 10;
            temp /= 10;
        }

        if (sum == multliplication) {
            printf("%d ", result);
        }

        result++;
    }

    return 0;
}
