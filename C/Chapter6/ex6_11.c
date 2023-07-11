#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    int ch;
    
    printf("Enter a character.\n");
    for (ch = getchar(); ch != EOF; ch = getchar()) {
        if (ch >= 'a' && ch <= 'z')
        ch -= 'a' - 'A';
        putchar(ch);
        putchar("\n");
        getchar(); // 입력시 발생한 개행문자(\n) 제거
        printf("Enter a character.\n");
    }
    return 0;
}