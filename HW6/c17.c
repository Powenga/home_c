// Сумма цифр равна произведению
// Составить логическую функцию, которая определяет, верно ли, что в заданном
// числе сумма цифр равна произведению. int is_happy_number(int n)

// Формат входных данных
// Целое не отрицательное число
// Формат результата
// YES или NO
// Примеры
// Входные данные
// 123
// Результат работы
// YES
// Входные данные
// 528
// Результат работы
// NO

#include <stdio.h>

int isHappyNumber(int input) {
    int sum = 0, multliplication = 1;
    while (input > 0) {
        sum += input % 10;
        multliplication *= input % 10;
        input /= 10;
    }
    if (sum == multliplication) {
        return 1;
    }

    return 0;
}

int main(void) {
    int input;
    scanf("%d", &input);
    if (input < 0) {
        printf("Введите положительное число");
    }

    printf(isHappyNumber(input) ? "YES" : "NO");
    return 0;
}