#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    int n;

    printf("Enter the number.\n");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }
    for (int i = 1; 2 * i - 1 <= n; i++) {
        for (int j = 1; 2 * j <= n - (2 * i)+1; j++) {
            printf(" ");
        }
        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}