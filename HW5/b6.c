#include <stdio.h>

int main(void) {
    int input, curr;
    int prev = -1;  // to avoid bug with 0 in last position of input
    scanf("%d", &input);

    while (input > 0) {
        curr = input % 10;
        if (curr == prev) {
            printf("YES");
            return 0;
        }
        prev = curr;
        input /= 10;
    }
    printf("NO");
    return 0;
}