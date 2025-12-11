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

void shiftArrayRight(int array[], int size) {
    int temp = array[size - 1];
    for (int i = size - 1; i > 0; i--) {
        array[i] = array[i - 1];
    }
    array[0] = temp;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}