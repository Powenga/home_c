// Количество 1
// Дано натуральное число N. Посчитать количество «1» в двоичной записи числа.

// Формат входных данных
// Натуральное число
// Формат результата
// Целое число - количество единиц в двоичной записи числа.
// Примеры
// Входные данные
// 5
// Результат работы
// 2
// Входные данные
// 255
// Результат работы
// 8

#include <stdio.h>

long long translateDecToAny(int num, int base) {
    if (base < 2 || base > 9) {
        printf("Основание должно быть больше 1 и меньше 10!");
        return 0;
    }

    if (num > 0) {
        return translateDecToAny(num / base, base) * 10 + (num % base);
    } else {
        return 0;
    }
}

int summDigits(long long num) {
    if (num <= 0) {
        return 0;
    }
    return num % 10 + summDigits(num / 10);
}

int main() {
    int input, res;
    scanf("%d", &input);
    if (input < 0) {
        printf("Введите не отрицательное число!");
    }

    printf("%d", summDigits(translateDecToAny(input, 2)));
    return 0;
}