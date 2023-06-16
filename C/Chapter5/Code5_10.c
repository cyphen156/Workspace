#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int is_digit(int ch);

int main(void) {
    char ch[4];
    int cnt = 0;
    printf("Enter a 3-letter word.\n");
    scanf("%s", ch);
    for (int i = 0; i < 3; i++) {
        if (is_digit(ch[i])) {
            cnt++;
        }
    }
    printf("Digit appears %d times.\n", cnt);
    return 0;
}

int is_digit(int ch){
    if (ch >= '0' && ch <= '9')
        return 1;
    else
        return 0;
}