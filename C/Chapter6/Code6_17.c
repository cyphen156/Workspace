#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    char ch;
    int state = 0, n = 0;
    printf("Enter a sentence.\n");

    while (1) {
        scanf("%c", &ch);
        if (ch == '\n')
            break;
        if (ch == 'i') {
            state = 1;
            continue;
        }
        if (state == 1 && ch == 'n') {
            state = 2;
            continue;
        }
        if (state == 2 && ch == ' ') {
            n++;
            state = 0;
            continue;
        }
        else
            state = 0;
    }
    printf("The preposition 'in' appears %d times.\n", n);
    return 0;
}