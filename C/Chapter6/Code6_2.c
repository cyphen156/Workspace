#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    int n, sum = 0, i = 0;

    printf("Enter a maximum number.\n");
    scanf("%d", &n);
    while (sum + i < n) {
        i++;
        sum += i;
    }
    printf("The sum from 1 to %d is %d", i, sum);
    return 0;
}