#include <stdio.h>

#define SIZE 10

int inputIntArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }
}

void swapArr(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubbleSort(int* arr, int n) {
    int noSwap;
    for (int i = 0; i < n; i++) {
        noSwap = 1;
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swapArr(arr, j + 1, j);
                noSwap = 0;
            }
        }

        if (noSwap) {
            break;
        }
    }
}

int main(void) {
    int arr[SIZE] = {0};
    inputIntArray(arr, SIZE);
    bubbleSort(arr, SIZE);
    printf("%d", arr[SIZE - 2] + arr[SIZE - 1]);
    return 0;
}
