// Скобки
// Проверить строку состоящую из скобок "(" и ")" на корректность.

// Формат входных данных
// На вход подается строка состоящая из символов '(', ')' и заканчивающаяся
// символом '.'. Размер строки не более 1000 символов. Формат результата
// Необходимо напечатать слово YES если скобки расставлены верно и NO в
// противном случае. Примеры Входные данные
// (()()).
// Результат работы
// YES
// Входные данные
// ()(.
// Результат работы
// NO

#include <stdio.h>

int main(void) {
    char input;
    int isClosed = 1;
    int openCount = 0;

    while ((input = getchar()) != '.') {
        if (input == '(') {
            isClosed = 0;
            openCount++;
        }
        if (!isClosed && input == ')') {
            openCount--;
            if (openCount == 0) {
                isClosed = 1;
            }
        } else if (isClosed && input == ')') {
            printf("NO");
            return 0;
        }
    }

    printf(openCount == 0 ? "YES" : "NO");
    return 0;
}