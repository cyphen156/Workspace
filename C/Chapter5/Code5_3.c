#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int calc(int price, int quan);

int main(void) {
    int unit_price, quantity, total;
    printf("단가와 개수를 입력하세오.\n");
    scanf("%d %d", &unit_price, &quantity);
    total = calc(unit_price, quantity);
    printf("%d", total);
    return 0;
}

int calc(int price, int quan) {
    int result = price * quan;
    if (quan >= 10) {
        result *= 0.95;
    }
    return result;
}