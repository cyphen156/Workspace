#define _CRT_SECURE_NO_WARNINGS
// 백준 2581 소수 판별
// 비효율적인 순회법 -> 약수 모두 순회
// 효율적으로 변경하려면? 원 수의 제곱근수 까지만 구하면된다.
#include <stdio.h>

int main() {
    // K == 자연수, limit M <= N <= 10000
    int M, N, K, sum = 0, min = 10001;
    scanf("%d %d", &M, &N);
    // N부터 M까지 순회
    for (int i = M; i <= N; i++) {
        int isPrime = 1;

        // 1은 소수가 아니니 예외처리
        if (i == 1)
            isPrime = 0;

        //소수 찾는 알고리즘 => 약수가 자기자신과 1
        for (int j = 2; j < i; j++) {
            // 약수가 나오면 소수가 아님
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
            // 약수가 안나오면 계속 순회
            else
                isPrime = 1;
        }
        if (isPrime == 1) {
            sum += i;
            if (min > i)
                min = i;
        }
    }
    // 소수가 없을 경우
    if (sum == 0) 
        printf("-1\n");
    else 
        printf("%d\n%d", sum, min);
    return 0;
}
