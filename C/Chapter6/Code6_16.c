#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    char ch; int sum = 0;
    int value;
    printf("Enter a natural number.\n");
    while (1) {
        scanf("%c", &ch);
        if (ch == '\n')
            break;
        if (ch < '0' || ch > '9') {
            printf("잘못된 입력입니다 숫자를 입력해주세요.\n");
            return 1;
        }
        value = ch - '0';
        sum = sum * 10 + value;
    }
    printf("You entered %d in decimal.\n", sum);
    return 0;
}