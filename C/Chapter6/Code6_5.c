#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    int num;
    printf("Enter a natural number.\n");
    scanf("%d", &num);
    for (int i = 1; i < num; i++) {
        if (num % i == 0)
            printf("%d ", i);
    }
    return 0;
}