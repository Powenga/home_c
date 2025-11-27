// От 1 до N
// Составить рекурсивную функцию, печать всех чисел от N до 1.

// Формат входных данных
// Одно натуральное число
// Формат результата
// Последовательность целых чисел от введенного числа до 1, через пробел.
// Примеры
// Входные данные
// 5
// Результат работы
// 5 4 3 2 1

#include <stdio.h>

void printNumReverse(int num) {
    printf("%d ", num);
    if (num > 1) {
        printNumReverse(num - 1);
    }
}

int main() {
    int input;
    scanf("%d", &input);
    if (input <= 0) {
        printf("Введите натуральное число!");
    }

    printNumReverse(input);
    return 0;
}