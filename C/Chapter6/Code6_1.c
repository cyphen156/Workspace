#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 3; j >= 1; j--) {
            printf("%d % d\n", i, j);
        }
    }
    return 0;
}