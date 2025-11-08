#include <stdio.h>

int main(void) {
    signed short int input;
    scanf("%hd", &input);

    if (input <= 0) {
        printf("Число должно быть натуральным");
        return 0;
    }

    if (input > 100) {
        printf("Число должно быть меньше 100");
        return 0;
    }

    for (signed short int i = 1; i <= input; i++) {
        printf("%hd %hd %hd\n", i, i * i, i * i * i);
    }

    return 0;
}