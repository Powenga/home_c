// Сумма цифр в тексте
// Составить функцию, которая преобразует текущий символ цифры в число. Написать
// программу считающую сумму цифр в тексте. int digit_to_num(char c)

// Формат входных данных
// Строка состоящая из английских букв, пробелов, знаков препинания. В конце
// строки символ точка. Формат результата Целое число - сумма цифр в тексте
// Примеры
// Входные данные
// 1Hello 36world.
// Результат работы
// 10
// Входные данные
// abc 1def2 3.
// Результат работы
// 6

#include <stdio.h>

int isIntChar(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}

int digitToNum(char c) { return c - '0'; }

int main(void) {
    char input;
    unsigned sum = 0;

    while ((input = getchar()) != '.') {
        if (isIntChar(input)) {
            sum += digitToNum(input);
        }
    }

    printf("%u", sum);
    return 0;
}