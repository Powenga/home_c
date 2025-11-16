// Сумма от 1 до N
// Составить функцию, которая определяет сумму всех чисел от 1 до N и привести
// пример ее использования.

// Формат входных данных
// Одно целое положительное число N
// Формат результата
// Целое число - сумма чисел от 1 до N
// Примеры
// Входные данные
// 100
// Результат работы
// 5050

#include <stdio.h>

unsigned int sum(unsigned int num) {
    unsigned int result = 0;
    for (int i = 0; i <= num; i++) {
        result += i;
    }
    return result;
}

int main(void) {
    unsigned int input;
    scanf("%u", &input);
    printf("%u", sum(input));
    return 0;
}
