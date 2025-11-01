#include <stdio.h>

int main(void) {
    int x1, y1, x2, y2;
    float k, b;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    /*
    y1 = k*x1 + b
    y2 = k*x2 + b

    y1 - y2 = k(x1 - x2)
    k = (y1 - y2) / (x1 - x2)
    b = y2 - k*x2

    */

    k = 1.0 * (y1 - y2) / (x1 - x2);
    b = y2 - k * x2;

    printf("%.2f %.2f\n", k, b);
    return 0;
}