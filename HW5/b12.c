#include <stdio.h>

int main(void) {
    unsigned input, curr, min = 9, max = 0;
    scanf("%u", &input);

    while (input > 0) {
        curr = input % 10;
        if (curr >= max) {
            max = curr;
        }
        if (curr <= min) {
            min = curr;
        }
        input /= 10;
    }

    printf("%u %u", min, max);
    return 0;
}