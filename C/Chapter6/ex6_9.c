#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    int ch;
    for (;;) {
        ch = getchar();
        if (ch == EOF) // -1
            break;
        else
            putchar(ch);
    }
    return 0;
}