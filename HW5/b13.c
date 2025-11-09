#include <stdio.h>

int main(void) {
    unsigned input, curr, countOdd = 0, countEven = 0;
    scanf("%u", &input);

    while (input > 0) {
        curr = input % 10;
        if (curr % 2 == 0) {
            countEven++;
        }
        else {
            countOdd++;
        }
        input /= 10;
    }

    printf("%u %u", countEven, countOdd);
    return 0;
}