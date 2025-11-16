// Функция по формуле
// Описать функцию вычисления f(x) по формуле:
// f(x)= x*x при -2 ≤ x < 2;
// x*x+4x+5 при x ≥ 2;
// 4 при x < -2.
// Используя эту функцию для n заданных чисел, вычислить f(x). Среди вычисленных
// значений найти наибольшее.

// Формат входных данных
// Последовательность не нулевых целых чисел, в конце последовательности число
// 0. Формат результата Одно целое число Примеры Входные данные 8 3 -3 10 0
// Результат работы
// 145
// Входные данные
// -2 -1 -3 1 0
// Результат работы
// 4

#include <stdio.h>

int func(int x) {
    if (x < -2) {
        return 4;
    }
    if (x >= -2 && x < 2) {
        return x * x;
    }
    return x * x + 4 * x + 5;
}

int main(void) {
    char c;
    int number = 0;
    int isNegative = 0;
    int max = 0;
    int hasContinue = 1;
    while (hasContinue) {
        c = getchar();
        if (c == '0' && number == 0) {
            hasContinue = 0;
        } else if (c == '-') {
            isNegative = 1;
        } else if (c >= '0' && c <= '9') {
            int charValue = c - '0';
            number = number * 10 + charValue;
        } else {
            if (isNegative) {
                number *= -1;
            }
            int result = func(number);
            if (result > max) {
                max = result;
            }
            number = 0;
            isNegative = 0;
        }
    }
    printf("%d", max);
    return 0;
}