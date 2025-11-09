#include <stdio.h>

int main(void) {
    unsigned int input, countEven = 0;
    while (1) {
        scanf("%d", &input);
        if (input == 0) {
            break;
        }
        if (input % 2 == 0) {
            countEven++;
        }
    }

    printf("%u", countEven);
    return 0;
}
