// Цифры по возрастанию
// Составить функцию логическую функцию, которая определяет, верно ли, что в
// заданном числе все цифры стоят по возрастанию. Используя данную функцию
// решить задачу. int grow_up(int n)

// Формат входных данных
// Одно целое не отрицательное число
// Формат результата
// YES или NO
// Примеры
// Входные данные
// 258
// Результат работы
// YES
// Входные данные
// 528
// Результат работы
// NO

#include <stdio.h>

int isGrowUp(int num) {
    int curr, prev = -1;
    while (num > 0) {
        curr = num % 10;
        if (prev != -1 && prev <= curr) {
            return 0;
        }
        prev = curr;
        num /= 10;
    }

    return 1;
}

int main(void) {
    int input;
    scanf("%d", &input);

    printf(isGrowUp(input) ? "YES" : "NO");
    return 0;
}