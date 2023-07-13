#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

static int len;    // 전역변수 len

int sizeCalc(char s[]); // 배열 길이 계산
int isAlpha(char s);  // 문자 하나 알파벳인지 확인
int toLower(char s);  // 문자 하나 대문자 변환

int main(void) {
    char s[100] = { 0 };
    scanf("%s", s);

    sizeCalc(s);
    for (int i = 0; i < len; i++) {
        int alphabet = 0;    // 알파벳이 아니라 가정
        printf("%c\t", s[i]);
        alphabet = isAlpha(s[i]);
        if (alphabet)    // 알파벳이 맞다면 대문자로 변환
            s[i] = toLower(s[i]);
        printf("%d\t%c\n", alphabet, toLower(s[i]));
    }
    printf("Final print is this.\n%s", s);
    return 0;
}

int sizeCalc(char s[]) {
    len = 0;
    for (int i = 0; s[i] != '\0'; i++)
        len++;
    return len;
}

int isAlpha(char s) {
    if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
        return 1;
    else
        return 0;
}

int toLower(char s){
    if (s >= 'A' && s <= 'Z')
        s += 32;  // 대문자를 소문자로 변환
    return s;
}