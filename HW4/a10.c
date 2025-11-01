#include <stdio.h>

int main(void) {
    int a, b, c, d, e;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    int min = a;

    if (min > b) {
        min = b;
    }
    if (min > c) {
        min = c;
    }
    if (min > d) {
        min = d;
    }
    if (min > e) {
        min = e;
    }

    printf("%d\n", min);
    return 0;
}