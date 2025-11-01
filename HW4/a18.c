#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);

    printf(a == b ? "Equal" : a < b ? "Less" : "Above");
    return 0;
}