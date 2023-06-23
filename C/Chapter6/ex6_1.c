#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    int sum = 0, count;
    count = 1;
    while (count <= 10){
        sum += count;
        count++;
    }
    printf("Sun of 1 to 10 is %d.\n", sum);
    return 0;
}
