#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    int n;
    double sum = 0.0f;

    printf("Enter the number of terms.\n");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0)
            sum -= 4 / (2.0 * i - 1.0);
        else 
            sum += 4 / (2.0 * i - 1.0);
        
    }
    printf("PI evaluated to %d terms is %.12f.", n, sum);
    return 0;
}