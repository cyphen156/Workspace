#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (i == 1 && j == 1)
                continue;
            if (i % j == 0)
                break;
            
        }
    }
    return 0;
}