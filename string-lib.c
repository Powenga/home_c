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

int getCountCharInWord(char* word, char c) {
    int count = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] == c) {
            count++;
        }
    }
    return count;
}

int isAlreadyAdded(char* result, char c) {
    for (int i = 0; result[i] != '\0'; i++) {
        if (result[i] == c) {
            return 1;
        }
    }
    return 0;
}

int compareChars(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}