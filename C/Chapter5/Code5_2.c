#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void is_vowel(char c);

int main(void) {
    char c;
    printf("소문자 하나를 입력하세요.\n");
    scanf("%c", &c);
    is_vowel(c);
    return 0;
}

void is_vowel(char c) {
    if (c < 'a' || c > 'z') {
        printf("소문자가 아닙니다.\n");
    }
    else {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            printf("Vowel\n");
        else
            printf("Consonant\n");
    }
}