#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    int input, n, idx = 0;
    char baseDigits[36];
    char result[100] = { 0 };

    for(int i = 0; i < 36; i++) {
        if(i < 10) {
            baseDigits[i] = '0' + i;
        } else {
            baseDigits[i] = 'A' + (i - 10);
        }
    }
    
    scanf("%d %d", &input, &n);
    
    while(input > 0) {
        result[idx++] = baseDigits[input % n];
        input /= n;
    }
    for (int i = idx - 1; i >= 0; i--) {
        printf("%c", result[i]);
    }
    return 0;
}
