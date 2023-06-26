#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    int num;
    do {
        printf("Enter a number to converted.\n");
        scanf("%d", &num);
        printf("%d is %X in hexadecimal.\n", num, num);
    } while (num >= 0);
    return 0;
}