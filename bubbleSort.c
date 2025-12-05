#include <stdio.h>

void swapArr(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void printArr(int* arr, int n) {
    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSortReverse(int* arr, int n) {
    int noSwap;
    for (int i = 0; i < n; i++) {
        noSwap = 1;
        for (int j = n - 1; j > i; j--) {
            if (arr[j - 1] > arr[j]) {
                swapArr(arr, j - 1, j);
                noSwap = 0;
            }
        }

        if (noSwap) break;
    }
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

        if (noSwap) break;
    }
}

int main(int argc, char const* argv[]) {
    int arr[6] = {10, 3, 24, 6, 5, 12};
    // bubbleSortReverse(arr, 6);
    // printf("reverse: ");
    // printArr(arr, 6);
    bubbleSort(arr, 6);
    printf("direct: ");
    printArr(arr, 6);
    return 0;
}
