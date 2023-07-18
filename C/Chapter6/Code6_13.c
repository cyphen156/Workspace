#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int calcLen(int n); // 자릿수 구하기
int power(int n, int len);    // 제곱
int narciss(int n); // returns 1 if narcissistic number

int main(void) {
    int n;

    printf("Enter a number.\n");
    scanf("%d", &n);

    if (narciss(n)) {
        printf("Yes, %d is a narcissistic number.\n", n);
    }
    else {
        printf("No, %d is not a narcissistic number.\n", n);
    }
    return 0;
}

int calcLen(int n) {
    int len = 0;
    while (n != 0) {
        n /= 10;
        len++;
    }
    return len;
}

int power(int n, int len) {
    if (len == 0)
        return 1;
    else
        return n * power(n, len - 1);
}

int narciss(int n) {
    int len = calcLen(n);
    int temp = n;
    int sum = 0;
    while (temp != 0) {
        int digit = temp % 10;
        sum += power(digit, len);
        temp /= 10;
    }
    return (sum == n);
}