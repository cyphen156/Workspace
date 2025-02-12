#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    int x, i;

    scanf("%d", &x);	
    // x = 대각선의 인덱스 -> 분자/분모의 최대치를 구하는 연산용
    // i ==> 구해진 X번째 대각선중 실제로 x가 존재 하는 위치
    for (i = 1; x > i; i++) {
        x -= i;
    }
    // 기본적으로 분모/분자는 0이아닌 실수 -=> 최소 값은 1이기 때문에 항상 최종적으로++연산이 필요함
    // i-x연산의 결과가 0이 나오면 안됨... 
    // 대각선이 짝수이면 분모 감소, 분자 증가
    if (i % 2 == 0) {
        printf("%d/%d\n", x, i - x + 1);
    }
    // 대각선이 짝수라면 분모 증가, 분자 감소
    else {
        printf("%d/%d\n", i - x + 1, x);
    }

    return 0;
}