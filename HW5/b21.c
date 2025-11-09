#include <stdio.h>

int main(void) {
    char input;

    while (input != '.') {
        scanf("%c", &input);
        if (input >= 'A' & input <= 'Z') {
            input += 'a' - 'A';
        }
        if (input == '.') {
            break;
        }
        printf("%c", input);
    }
    return 0;
}
