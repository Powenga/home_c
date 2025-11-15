#include <stdio.h>

int power(int n, int p) {
    int result = 1;
    for (int i = 0; i < p; i++) {
        result *= n;
    }
    return result;
}

int main() {
    int number, pow;
    scanf("%d %d", &number, &pow);
    printf("%d", power(number, pow));
    return 0;
}