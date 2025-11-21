// Перевести число N в систему счисления P
// Составить функцию, которая переводит число N из десятичной системы счисления
// в P-ичную систему счисления.

// Формат входных данных
// Два целых числа. N ≥ 0 и 2 ≤ P ≤ 9
// Формат результата
// Одно целое число
// Примеры
// Входные данные
// 25 5
// Результат работы
// 100
// Входные данные
// 9 2
// Результат работы
// 1001
// Входные данные
// 11 3
// Результат работы
// 102

#include <stdio.h>

long long translateDecToAny(int dec, int base) {
    long long result = 0;
    int multiplier = 1;
    while (dec > 0) {
        result += dec % base * multiplier;
        dec /= base;
        multiplier *= 10;
    }
    return result;
}

int main(void) {
    int dec, base;
    scanf("%d %d", &dec, &base);
    if (dec < 0) {
        printf("Число должно быть не меньше 0");
        return 0;
    }
    if (base < 2 || base > 9) {
        printf("Основание должно быть не меньше 2 и не больше 9");
        return 0;
    }
    printf("%lld", translateDecToAny(dec, base));
    return 0;
}
