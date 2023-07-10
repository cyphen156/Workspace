#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    //a = 15, b = 6, result = 연산 결과, carry == 올림 수
    int a[2] = { 1, 5 }, b[2] = { 0, 6 }, result[2] = { 0 }, carry = 0;
    for (int i = 1; i >= 0; i--) {
        //정수형 배열의 일의자리 부터 연산해야 하므로 배열의 역순으로 순회
        int temp = a[i] + b[i];
        if (carry == 1) {
            temp++;
            carry = 0;
        }
        if (temp >= 10) {//올림 수가 발생하면
            carry = 1;
        }
        result[i] = temp % 10;
    }
    for (int i = 0; i < 2; i++) {
        printf("%d", result[i]);
    }
    return 0;
}
