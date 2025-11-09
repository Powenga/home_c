#include <stdio.h>

int main(void) {
    signed int input, sum = 0;
    scanf("%d", &input);

    if (input <= 0) {
        printf("Введите натуральное число");
    }

    while (input > 0) {
        sum += input % 10;
        input /= 10;
    }

    printf(sum == 10 ? "YES" : "NO");

    return 0;
}
