#include <stdio.h>
#include <stdlib.h>

int main(void) {
    signed short int a, b;
    unsigned int sum = 0;
    scanf("%hd %hd", &a, &b);

    if (abs(a) > 100 || abs(b) > 100) {
        printf("Число должно быть не больше 100");
        return 0;
    }

    if (a > b) {
        printf("Число a должно быть не больше числа b");
        return 0;
    }

    for (signed short int i = a; i <= b; i++) {
        sum += i * i;
    }

    printf("%u", sum);
    return 0;
}