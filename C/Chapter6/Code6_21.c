#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int bin_to_dec(long long n);

int main(void) {
    long long int n;

    printf("Enter a binary number.\n");
    scanf("%lld", &n);  // 입력을 한글자 단위가 아닌 전체 숫자로 받겟다는 소리입니다
                        // ex 11011110101010111101101
    printf("The decimal value of binary %lld is %d.", n, bin_to_dec(n));
    return 0;
}

int bin_to_dec(long long n) {
    int result = 0, base = 1;
    while (n > 0) {
        int remainder = n % 10;
        result += remainder * base;
        base *= 2;
        n /= 10;
    }

    return result;
}