// Вычислить cos
// Составить функцию, которая вычисляет косинус как сумму ряда (с точностью
// 0.001)

// cos(x) = 1 - x^2/2! + x^4/4! - x^6/6! + ... (x в радианах)

// float cosinus(float x)
// Формат входных данных
// Целое число от 0 до 90
// Формат результата
// Вещественное число в формате "%.3f"
// Примеры
// Входные данные
// 60
// Результат работы
// 0.500

#include <stdio.h>

float power(float n, int p) {
    float result = 1;
    for (int i = 0; i < p; i++) {
        result *= n;
    }
    return result;
}

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result = result * i;
    }
    return result;
}

float cosinus(int x) {
    float rads = x * 3.141 / 180;
    float result = 1;
    int sign = -1;
    int length = 6;
    for (int i = 2; i <= length; i += 2) {
        result = result + sign * power(rads, i) / factorial(i);
        sign *= -1;
    }
    return result;
}

int main(void) {
    int input;
    scanf("%d", &input);
    printf("%.3f", cosinus(input));
    return 0;
}