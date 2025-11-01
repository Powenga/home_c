#include <stdio.h>

int main(void) {
    int a, b, c, d, e;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    int max = a;

    if (max < b) {
        max = b;
    }
    if (max < c) {
        max = c;
    }
    if (max < d) {
        max = d;
    }
    if (max < e) {
        max = e;
    }

    printf("%d\n", max);
    return 0;
}