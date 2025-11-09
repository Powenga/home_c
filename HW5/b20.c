#include <stdio.h>

int main(void) {
    signed int input;
    scanf("%d", &input);

    if (input <= 0) {
        printf("Введите натуральное число");
    }

    if (input == 1) {
        printf("NO");
        return 0;
    }

    for (int i = 2; i < input; i++) {
        if (input % i == 0) {
            printf("NO");
            return 0;
        }
    }

    printf("YES");
    return 0;
}
