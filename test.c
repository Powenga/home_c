#include <stdio.h>

int main() {
    int f[5] = {0};
    int arr[4] = {0};
    printf("arr: ");

    for (int i = 0; i < 4; i++) {
        printf("%d ", arr[i]);
    }
    int i = 0;

    f[i++] = 3.14;

    printf("\nf: ");

    for (int i = 0; i < 4; i++) {
        printf("%d ", f[i]);
    }

    return 0;
}