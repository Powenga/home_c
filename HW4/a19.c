#include <stdio.h>

int main(void) {
    int a, b, c, max, side1, side2;
    scanf("%d %d %d", &a, &b, &c);
    // if sum of any sides is bigger than other side
    // check sides
    if (a <= 0 || b <= 0 || c <= 0) {
        printf("NO");
        return 0;
    }
    // find max side
    if (a >= b && a >= c) {
        max = a;
        side1 = b;
        side2 = c;
    } else if (b >= a && b >= c) {
        max = b;
        side1 = a;
        side2 = c;
    } else if (c >= a && c >= b) {
        max = c;
        side1 = a;
        side2 = b;
    }

    printf(max < side1 + side2 ? "YES" : "NO");
    return 0;
}