#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void reverse_it(int num);

int main(void) {
    int n;

    while (1) {
        printf("Enter a natural number.\n");
        scanf("%d", &n);
        if (n <= 0)
            break;
        reverse_it(n);
        printf("\n");
    }
    return 0;
}

void reverse_it(int num) {
    while (num != 0) {
        int k = num % 10;
        num /= 10;
        printf("%d", k);
    }
}