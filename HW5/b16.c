#include <stdio.h>

int main(void) {
    unsigned int a, b, t;

    scanf("%u %u", a, b);

    while (b != 0) {
        t = b;
        b = a % b;
        a = t;
    }

    printf("%u\n", a);
    return 0;
}
