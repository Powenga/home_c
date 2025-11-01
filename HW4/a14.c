#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int a, b, c;

    a = n % 10;
    b = (n / 10) % 10;
    c = (n / 100) % 10;

    printf("%d\n", a > b ? (a > c ? a : c) : (b > c) ? b : c);
    return 0;
}