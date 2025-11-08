#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int input, count = 0;
    scanf("%d", &input);

    while (input > 0) {
        count++;
        if (count > 3) {
            break;
        }
        input /= 10;
    }

    printf(count == 3 ? "YES" : "NO");
    return 0;
}