#include <stdio.h>

#define SIZE 12

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int printIntArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
}

int inputIntArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }
}

void inverseArrayHalf(int arr[], int length) {
    for (int i = 0; i < length / 3 / 2; i++) {
        swap(&arr[i], &arr[length / 3 - i - 1]);
        swap(&arr[length / 3 + i], &arr[length / 3 * 2 - i - 1]);
        swap(&arr[length / 3 * 2 + i], &arr[length - i - 1]);
    }
}

int main(void) {
    int arr[SIZE] = {0};
    inputIntArray(arr, SIZE);
    inverseArrayHalf(arr, SIZE);
    printIntArray(arr, SIZE);
    return 0;
}
