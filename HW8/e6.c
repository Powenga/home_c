#include <stdio.h>

#define SIZE 12

int inputIntArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }
}

float getInteArrayAverage(int arr[], int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += arr[i];
    }
    return (float)sum / length;
}

int main(void) {
    int arr[SIZE] = {0};
    inputIntArray(arr, SIZE);
    printf("%.2f", getInteArrayAverage(arr, SIZE));
    return 0;
}
