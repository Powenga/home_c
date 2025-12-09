#include <stdio.h>

#define SIZE 10

int inputIntArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }
}

int sumPositiveItemsOfArray(int arr[], int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        if (arr[i] > 0) {
            sum += arr[i];
        }
    }
    return sum;
}

int main(void) {
    int arr[SIZE] = {0};
    inputIntArray(arr, SIZE);
    printf("%d", sumPositiveItemsOfArray(arr, SIZE));
    return 0;
}
