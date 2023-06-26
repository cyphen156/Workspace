#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int total(int, double, int);

int main(void) {
    int principal; double interest; int years;  //원금, 연리, 햇수
    printf("Enter principal, annual interest, and years.\n");
    scanf("%d%lf%d", &principal, &interest, &years);
    printf("Total is %d.\n", total(principal, interest, years));
    return 0;
}

int total(int p, double i, int y) {
    double rate = 1.0;
    while (y > 0) {
        rate *= (1.0+i);
        y--;
    }
    return (int)(p*rate);
}