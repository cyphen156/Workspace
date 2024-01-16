#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>

double divide(int a, int b) {
    return (double)a / b;
}

int main() {
    int A, B;
    double result;
    scanf("%d %d", &A,&B);
    result = divide(A, B);
    printf("%.9lf", result);
    return 0;
}