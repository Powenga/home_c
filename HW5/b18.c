#include <stdio.h>

int main(void) {
    signed int n, f1 = 0, f2 = 1, m;
    scanf("%d", &n);

    if (n <= 0) {
        printf("Введите натуральное число");
    }

    if (n == 1) {
        printf("1");
        return 0;
    }

    printf("1 ");
    for (int i = 1; i < n; i++) {
        m = f1 + f2;
        f1 = f2;
        f2 = m;
        printf("%d ", m);
    }
    return 0;
}
