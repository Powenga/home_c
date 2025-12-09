#include <stdio.h>

#define SIZE 5

int inputIntArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }
}

int findArrayMin(int arr[], int length) {
    int min = arr[0];
    for (int i = 0; i < length; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main(void) {
    int arr[SIZE] = {0};
    inputIntArray(arr, SIZE);
    printf("%d", findArrayMin(arr, SIZE));
    return 0;
}
