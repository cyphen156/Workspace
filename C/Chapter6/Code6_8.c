#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    int n, num = 0, sum = 0;

    printf("Enter the number of terms.\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        num = 10 * num + 9;
        sum += num;
    }
    printf("The sum is %d.\n", sum);
    return 0;
}
