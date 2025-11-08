#include <stdio.h>

int main(void) {
    unsigned input, result = 0;
    unsigned int curr;
    scanf("%u", &input);

    while (input > 0) {
        result = result * 10 + input % 10;
        input /= 10;
    }

    printf("%u", result);
    return 0;
}