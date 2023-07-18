#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    int len = 0;
    double n, sum = 0.0f, avg = 0.0f;

    while (1) {
        printf("Enter a natural number.\n");
        scanf("%lf", &n);
        if (n <= 0)
            break;
        sum += n;
        len++;
        avg = sum / len;
        printf("Current avverage is %.3lf\n", avg);
    }
    return 0;
}