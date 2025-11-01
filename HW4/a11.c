#include <stdio.h>

int main(void) {
    int a, b, c, d, e;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    int max = a, min = a;

    if (max < b) {
        max = b;
    }
    if (min > b) {
        min = b;
    }

    if (max < c) {
        max = c;
    }
    if (min > c) {
        min = c;
    }

    if (max < d) {
        max = d;
    }
    if (min > d) {
        min = d;
    }

    if (max < e) {
        max = e;
    }
    if (min > e) {
        min = e;
    }

    printf("%d\n", min + max);
    return 0;
}