#define _CRT_SECURE_NO_WARNINGS

int is_vowel(char c);
#include <stdio.h>

int main(void) {
    char c;
    printf("소문자를 하나 입력하세요.\n");
    scanf("%c", &c);
    is_vowel(c);
    return 0;
}

int is_vowel(char c) {
    if (c < 97 || c > 123) {
        printf("소문자가 아닙니다");
        return;
    }
    else {
        if (c == '97' || c == '101' || c == '105' || c == '111' || c == '117')
            printf("Consonant\n");
        else
            printf("Vowel\n");
    }
    return 1;
}