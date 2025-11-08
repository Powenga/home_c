#include <stdio.h>

int main(void) {
    int input, curr, prev = -1;
    scanf("%d", &input);

    while (input > 0) {
        curr = input % 10;
        if (prev != -1 && prev <= curr) {
            printf("NO");
            return 0;
        }
        prev = curr;
        input /= 10;
    }

    printf("YES");
    return 0;
}