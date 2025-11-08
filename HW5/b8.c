#include <stdio.h>

int main(void) {
    int input, curr, remainder, count = 0, target = 9;
    scanf("%d", &input);

    while (input > 0) {
        if (count > 1) {
            printf("NO");
            return 0;
        }
        curr = input % 10;
        if (curr == target) {
            count++;
        }
        input /= 10;
    }

    printf(count == 1 ? "YES" : "NO");
    return 0;
}