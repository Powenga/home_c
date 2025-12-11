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

void shiftArrayLeft(int array[], int size) {
    int temp = array[0];
    for (int i = 0; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    array[size - 1] = temp;
}

void shiftArrayLeftPartial(int array[], int size, int startIndex) {
    int temp = array[startIndex];
    for (int i = startIndex; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    array[size - 1] = temp;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}