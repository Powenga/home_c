// Факториал
// Составить функцию вычисления N!. Использовать ее при вычислении факториала
// int factorial(int n)

// Формат входных данных
// Целое положительное число не больше 20
// Формат результата
// Целое положительное число
// Примеры
// Входные данные
// 5
// Результат работы
// 120

#include <stdio.h>

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result = result * i;
    }
    return result;
}

int main(void) {
    int input;
    scanf("%d", &input);
    printf("%d", factorial(input));
    return 0;
}
