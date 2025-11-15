#include <stdio.h>

int middle(int a, int b) { return (a + b) / 2; }

int main() {
    int a, b;
    scanf("%u %u", &a, &b);
    if (a < 0 || b < 0) {
        printf("Введите не отрицательные числа!");
        return 0;
    }
    printf("%u", middle(a, b));
    return 0;
}