#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void calc(double a, double b, double c);

int main(void) {
    double a, b, c;
    printf("Enter three real numbers.\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    if (a <= 0 || b <= 0 || c <= 0) {
        printf("변의 길이는 항상 양수여야 합니다.\n");
        return 0;
    }
    calc(a, b, c);
    return 0;
}

void calc(double a, double b, double c) {
    if (a + b < c || b + c < a || c + a < b) {
        printf("No such triangle");
    }
    else
        printf("%lf", a + b + c);
}