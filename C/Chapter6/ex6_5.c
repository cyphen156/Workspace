#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    int num;

    printf("Enter a number to be converted.\n");
    scanf("%d", &num);
    while (num >= 0) {
        printf("%d is %X in hexadecimal.\n", num, num);
        printf("Enter a number to be converted.\n");
        scanf("%d", &num);
    }
    return 0;
}