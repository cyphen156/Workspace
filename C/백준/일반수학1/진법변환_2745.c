#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int power(int base, int exponent);

int main(void) {
    char s[100];
    int n, len, result = 0;
    int nArray[100] = { 0 };    //원본 보존용 변환 정수형 배열
    scanf("%s %d", s, &n);
    for (len = 0; s[len] != '\0'; len++);
    for (int i = 0; i < len; i++) {
        if ('0' <= s[i] && s[i] <= '9')
            nArray[i] = s[i] - '0';
        else if ('A' <= s[i] && s[i] <= 'Z')
            nArray[i] = s[i] - 'A' + 10;
    }
    for (int i = 0; i < len; i++) {
        result += nArray[i] * power(n, len-i-1);
    }
    printf("%d", result);
    return 0;
}

int power(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}
