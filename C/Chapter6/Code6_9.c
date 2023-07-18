#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    int n, sum = 0;

    printf("Enter the number.\n");
    scanf("%d", &n);
    if (n < 0 || n >= 10000){
        pritnf("잘못된 수를 입력했습니다. 프로그램을 종료합니다.\n");
        return 0;
    }
    while (n > 0) {
        sum += n % 10;
        n /= 10;      
    }
    printf("The sum is %d.\n", sum);
    return 0;
}
