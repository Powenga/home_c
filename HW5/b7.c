#include <stdio.h>

int main(void) {
    int input, curr, remainder;
    scanf("%d", &input);

    while (input > 0) {
        curr = input % 10;
        remainder = input / 10;
        while (remainder > 0) {
            if (curr == remainder % 10) {
                printf("YES");
                return 0;
            }
            remainder /= 10;
        }
        input /= 10;
    }

    printf("NO");
    return 0;
}