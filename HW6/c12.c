// Вычислить sin
// Составить функцию, которая вычисляет синус как сумму ряда (с точностью 0.001)

// sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...(x в радианах)

// float sinus(float x)
// Формат входных данных
// Одно число от 0 до 90
// Формат результата
// Вещественное число в формате "%.3f"
// Примеры
// Входные данные
// 45
// Результат работы
// 0.707
// Входные данные
// 30
// Результат работы
// 0.500
// Входные данные
// 0
// Результат работы
// 0.000

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

float sinus(int x) {
    float rads = x * 3.141 / 180;
    float result = rads;
    int sign = -1;
    int length = 7;
    for (int i = 3; i <= length; i += 2) {
        result = result + sign * power(rads, i) / factorial(i);
        sign *= -1;
    }
    return result;
}

int main(void) {
    int input;
    scanf("%d", &input);
    printf("%.3f", sinus(input));
    return 0;
}