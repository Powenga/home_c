#include <stdio.h>

#define SIZE 20

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

void sort_even_odd(int n, int a[]) {
    int temp[n];
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            temp[index] = a[i];
            index++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            temp[index] = a[i];
            index++;
        }
    }

    for (int i = 0; i < n; i++) {
        a[i] = temp[i];
    }
}

int inputIntArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }
}

int main(void) {
    int arr[SIZE] = {0}, n = 0;
    inputIntArray(arr, SIZE);
    sort_even_odd(SIZE, arr);
    printIntArray(arr, SIZE);
    return 0;
}
