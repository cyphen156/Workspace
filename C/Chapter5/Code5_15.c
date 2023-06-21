#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int sumAll(int p, int c, int e);

int main(void) {
    int price, cnt, express, sum = 0;
    printf("단가를 입력하세요.\n");
    scanf("%d", &price);
    printf("개수를 입력하세요.\n");
    scanf("%d", &cnt);
    printf("급행 여부를 입력하세요. (1: 급행, 0: 아님)\n");
    scanf("%d", &express);
    sum = sumAll(price, cnt, express);
    printf("지불해야 할 총액은 %d원 입니다.\n", sum);
    return 0;
}


int sumAll(int p, int c, int e) {
    int result = 0;
    result = p * c;
    if (result >= 20000) {
        result += 1500;
    }
    else {
        result += 2000;
    }
    if (e != 0) {
        result += 1000;
    }
    return result;
}