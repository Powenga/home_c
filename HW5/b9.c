#include <stdio.h>

int main(void) {
    int input, curr;
    scanf("%d", &input);

    while (input > 0) {
        curr = input % 10;
        if (curr % 2 != 0) {
            printf("NO");
            return 0;
        }
        input /= 10;
    }

    printf("YES");
    return 0;
}