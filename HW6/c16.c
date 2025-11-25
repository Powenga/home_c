// Проверка на простоту
// Составить функцию логическую функцию, которая определяет, верно ли, что число
// простое. Используя функцию решить задачу. int is_prime(int n)

// Формат входных данных
// Одно целое не отрицательное число.
// Формат результата
// YES или NO
// Примеры
// Входные данные
// 13
// Результат работы
// YES
// Входные данные
// 136
// Результат работы
// NO

#include <stdio.h>

int isPrime(int input) {
    if (input == 1 || input == 0) {
        return 0;
    }

    for (int i = 2; i < input; i++) {
        if (input % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int input;
    scanf("%d", &input);
    if (input < 0) {
        printf("Введите натуральное число");
    }

    printf(isPrime(input) ? "YES" : "NO");
    return 0;
}