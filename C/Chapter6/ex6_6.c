#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    int num;

    while (1) {
        printf("Enter a number to be converted.\n");
        scanf("%d", &num);
        if (!(num >= 0))
            break;
        printf("%d is %X in hexadecimal.\n", num, num);
    }
    return 0;
}