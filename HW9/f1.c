#include <stdio.h>

#define SIZE 20

static int maxx123() { printf("f1.c"); }

int printIntArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
}

void sort_array(int size, int a[]) {
    int noSwap;
    for (int i = 0; i < size; i++) {
        noSwap = 1;
        for (int j = 0; j < size - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                noSwap = 0;
            }
        }

        if (noSwap) break;
    }
}

int main(void) {
    maxx123();
    return 0;
}
