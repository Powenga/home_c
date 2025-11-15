#include <stdio.h>

int abs(int number) { return number < 0 ? number * -1 : number; }

int main() {
    int input;
    scanf("%d", &input);
    printf("%d", abs(input));
    return 0;
}