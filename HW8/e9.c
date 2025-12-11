#include <stdio.h>

#define SIZE 10

void shiftArrayRight(int array[], int size) {
    int temp = array[size - 1];
    for (int i = size - 1; i > 0; i--) {
        array[i] = array[i - 1];
    }
    array[0] = temp;
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

int main(void) {
    int arr[SIZE] = {0};
    inputIntArray(arr, SIZE);
    shiftArrayRight(arr, SIZE);
    printIntArray(arr, SIZE);
    return 0;
}
