#include <stdio.h>

int main(void) {
    unsigned int input, count = 0;
    while (1) {
        scanf("%u", &input);
        if (input == 0) {
            break;
        }
        count++;
    }

    printf("%u", count);
    return 0;
}
