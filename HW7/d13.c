// Печать простых множителей
// Составить рекурсивную функцию, печать всех простых множителей числа.

// Формат входных данных
// Натуральное число
// Формат результата
// Последовательность из всех простых делителей числа через пробел
// Примеры
// Входные данные
// 12
// Результат работы
// 2 2 3
// Входные данные
// 120
// Результат работы
// 2 2 2 3 5

#include <stdio.h>

void printPrimeDevider(int num, int delitel) {
    if (delitel > num) {
        return;
    }
    if (num % delitel == 0) {
        printf("%d ", delitel);
        num /= delitel;
    } else {
        delitel += 1;
    }
    printPrimeDevider(num, delitel);
}

int main() {
    int input;
    scanf("%d", &input);

    if (input < 1) {
        printf("Введите число больше 1!");
    }

    printPrimeDevider(input, 2);
    return 0;
}