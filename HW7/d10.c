// Проверка на простоту
// Дано натуральное число n ≥ 1. Проверьте, является ли оно простым. Программа
// должна вывести слово YES, если число простое или NO в противном случае.
// Необходимо составить рекурсивную функцию и использовать ее. int is_prime(int
// n, int delitel)

// Формат входных данных
// Натуральное число
// Формат результата
// YES или NO
// Примеры
// Входные данные
// 11
// Результат работы
// YES
// Входные данные
// 12
// Результат работы
// NO
// Входные данные
// 73
// Результат работы
// YES

#include <stdio.h>

int isPrime(int num, int delitel) {
    if (num == 1) {
        return 0;
    }
    if (delitel * delitel > num) {
        return 1;
    }
    if (num % delitel == 0) {
        return 0;
    }
    return isPrime(num, delitel + 1);
}

int main() {
    int input;
    scanf("%d", &input);

    if (input < 1) {
        printf("Введите число больше 1!");
    }

    printf(isPrime(input, 2) ? "YES" : "NO");
    return 0;
}