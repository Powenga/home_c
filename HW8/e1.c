#include <stdio.h>

#define SIZE 5

int inputIntArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }
}

float findArrayAverage(int arr[], int length) {
    float sum = 0;
    for (int i = 0; i < length; i++) {
        sum += arr[i];
    }
    return sum / length;
}

int main(void) {
    int arr[SIZE] = {0};
    inputIntArray(arr, SIZE);
    printf("%.3f", findArrayAverage(arr, SIZE));
    return 0;
}
