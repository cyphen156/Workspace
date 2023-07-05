#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    int results[100][4];    //0.25, 0.1, 0.05, 0.01$
    // sum == always be under 5.0,cant use dollars
    int n, input;   //input == cent(0.01)
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &input);

        results[i][0] = input / 25;
        input %= 25;

        results[i][1] = input / 10;
        input %= 10;

        results[i][2] = input / 5;
        input %= 5;

        results[i][3] = input;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", results[i][j]);
        }
        printf("\n");
    }
    return 0;
}

//  백준에 제출하면 런타임 에러가 발생합니다 results의 0번 인덱스 크기를 500으로 늘리면 해결되지만 저는 이게 문제오류라고 생각합니다.// 