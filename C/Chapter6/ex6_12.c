#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    int sum, count;
    for (sum = 0, count = 1; count <= 0; ) {
        sum += count++;
    }
    printf("Sum of 1 to 10 is  %d.\n", sum);
    return 0;
}