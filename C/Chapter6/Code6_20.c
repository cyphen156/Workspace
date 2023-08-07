#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    char ch;
    int len = 0, isNum = 0, head = 0;

    printf("Enter an identifier.\n");
    while (1) {
        scanf("%c", &ch);
        if (ch == '\n')
            break;
        if (len == 0 && ch >= 'a' && ch <= 'z') {
            head = 1;
        }
        if (ch >= '0' && ch <= '9') {
            isNum = 1;
        }
        len++;
    }
    if (isNum == 1 && len <= 8 && head == 1)
        printf("It's a legal ID.\n");
    else
        printf("It's a Unlegal ID.\n");
    return 0;
}