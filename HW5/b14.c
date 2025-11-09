#include <stdio.h>

int main(void) {
    unsigned int input, count = 0;
    while (1) {
        scanf("%d", &input);
        if (input == 0) {
            break;
        }
        count++;
    }

    printf("%d", count);
    return 0;
}
