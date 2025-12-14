void printStringDigits(char a[]) {
    int counts[10] = {0};

    for (int i = 0; a[i] != '\0'; i++) {
        if (a[i] > '0' && a[i] < '9') {
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