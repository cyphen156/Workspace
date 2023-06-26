#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    int sum = 0;
    for (int i = 1; i <= 10; i++) {
        sum += i;
    }
    printf("%d\n", sum);
    return 0;
}