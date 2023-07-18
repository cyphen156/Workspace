#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    int n, sum = 0;

    printf("Enter a natural number.\n");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        if (i % 5 == 0)
            continue;
        sum += i;
    }
    printf("The sum is %d", sum);
    return 0;
}