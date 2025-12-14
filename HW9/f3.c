#include <stdio.h>

int printIntArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
}

void countIntChars(char a[]) {
    int counts[10] = {0};

    for (int i = 0; a[i] != '\0'; i++) {
        int num = a[i] - '0';
        counts[num]++;
    }

    for (int i = 0; i < 10; i++) {
        if (counts[i] > 0) {
            printf("%d %d\n", i, counts[i]);
        }
    }
}

int main(void) {
    char arr[1000];
    scanf("%[0-9]", &arr);
    countIntChars(arr);
    return 0;
}
