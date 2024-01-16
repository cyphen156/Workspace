#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void calc(int a, int b) {
    printf("%d\n", a + b);
    printf("%d\n", a - b);
    printf("%d\n", a * b);
    printf("%d\n", a / b);
    printf("%d\n", a % b);
}

int main() {
    int A, B;
    scanf("%d %d", &A,&B);
    calc(A, B);
    return 0;
}