#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    int num, max, sum = 0;

    printf("Enter an integer larger than 1.\n");
    scanf("%d", &max);
    for (num = 1; num <= max; num++) {
        if (num % 2 == 1)
            sum += num;
    }
    printf("Sum of odd numbers from 1 to %d is %d.\n", max, sum);
    return 0;
}