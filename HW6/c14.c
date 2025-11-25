// Сумма цифр четна
// Составить функцию логическую функцию, которая определяет, верно ли, что сумма
// его цифр – четное число. Используя эту функцию решить задачу.

// Формат входных данных
// Одно целое не отрицательное число
// Формат результата
// Ответ YES или NO
// Примеры
// Входные данные
// 136
// Результат работы
// YES
// Входные данные
// 245
// Результат работы
// NO

#include <stdio.h>

int summOfNumbers(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

int isEven(int num) { return num % 2 == 0 ? 1 : 0; }

int main(void) {
    int input;
    scanf("%d", &input);

    printf(isEven(summOfNumbers(input)) ? "YES" : "NO");
    return 0;
}