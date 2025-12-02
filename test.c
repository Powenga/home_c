#include <stdio.h>

int main() {
    int a[3][2];
    int (*pm)[2];
    a[1][1] = 146;
    pm = a;

    printf("%d - %d", a[1][1], pm[1][1]);
    return 0;
}