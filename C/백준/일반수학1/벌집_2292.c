/*
    벌집만드는 알고리즘 = 단계마다 6(n)개의 방씩 늘어남
    ->  n 만큼 이동해야 한다.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    int N, result = 1, i;
    scanf("%d", &N);
    for (i = 1; result < N; i++) {
        result += 6 * i;
    }
    printf("%d", i);
    return 0;
}
