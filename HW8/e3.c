#include <stdio.h>

#define SIZE 10

typedef struct {
    int value;
    int position;
} arrayItemWithPosition;

int inputIntArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }
}

arrayItemWithPosition findArrayMinItem(int arr[], int length) {
    arrayItemWithPosition item = {arr[0], 0};
    for (int i = 0; i < length; i++) {
        if (arr[i] < item.value) {
            item.value = arr[i];
            item.position = i;
        }
    }
    return item;
}

arrayItemWithPosition findArrayMaxItem(int arr[], int length) {
    arrayItemWithPosition item = {arr[0], 0};
    for (int i = 0; i < length; i++) {
        if (arr[i] > item.value) {
            item.value = arr[i];
            item.position = i;
        }
    }
    return item;
}

int main(void) {
    int arr[SIZE] = {0};
    inputIntArray(arr, SIZE);
    arrayItemWithPosition min = findArrayMinItem(arr, SIZE);
    arrayItemWithPosition max = findArrayMaxItem(arr, SIZE);
    printf("%d %d %d %d", max.position + 1, max.value, min.position + 1,
           min.value);
    return 0;
}
