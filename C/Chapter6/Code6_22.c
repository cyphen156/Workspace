#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int clac_len(int n);

int main(void) {
    int n;

    printf("Enter a number.\n");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int len = clac_len(i);
        int temp = i;
        int clap = 0;
        for (int j = 0; j < len; j++) {
            int digit = temp % 10;
            if (digit == 3 || digit == 6 || digit == 9) {
                clap++;
            }
            temp /= 10;
        }
        if (clap > 0) {
            for (int k = 0; k < clap; k++) {
                printf("!");
            }
        }
        else {
            printf("%d", i);
        }
        printf(" ");
    }
    return 0;
}

int clac_len(int n) {
    int result = 0;
    while (n > 0) {
        n /= 10;
        result++;
    }
    return result;
}