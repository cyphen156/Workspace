#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int multi(int a, int b) {
    return a * b;
}

int main() {
    int A, B, result;
    scanf("%d %d", &A, &B);
    result = multi(A, B);
    printf("%d", result);
    return 0;
}
