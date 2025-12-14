#include <stdio.h>

int printIntArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
}

void print_digit(char a[]) {
    int counts[10] = {0};

    for (int i = 0; a[i] != '\0'; i++) {
        char test = a[i];
        if (a[i] >= '0' && a[i] <= '9') {
            int num = a[i] - '0';
            counts[num]++;
        }
    }

    for (int i = 0; i < 10; i++) {
        if (counts[i] > 0) {
            printf("%d %d\n", i, counts[i]);
        }
    }
}

int main(void) {
    char arr[1000];
    scanf("%[^\n]", &arr);
    print_digit(arr);
    return 0;
}
