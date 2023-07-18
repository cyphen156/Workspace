#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int power(int a, int b);

int main(void) {
    int a, b;
    printf("Enter a natural number.\n");
    scanf("%d %d", &a, &b);
    printf("%d to the power of %d is %d.", a, b, power(a, b));
    return 0;
}

int power(int a, int b) {
    if (b == 0)
        return 1;
    else
        return a * power(a, b - 1);
}