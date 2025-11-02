#include <stdio.h>

int main(void) {
    int month;
    scanf("%d", &month);
    if (month == 12 || month == 1 || month == 2) {
        printf("winter");
    } else if (month == 3 || month == 4 || month == 5) {
        printf("spring");
    } else if (month == 6 || month == 7 || month == 8) {
        printf("summer");
    } else if (month == 9 || month == 10 || month == 11) {
        printf("autumn");
    } else {
        printf("Wrong month number!");
    }
    return 0;
}