#define _CRT_SECURE_NO_WARNINGS
/*
    백준 24265 알고리즘 수업 - 알고리즘의 수행 시간 4
    반복횟수 = 중첩for문
    반복횟수가 등차수열의 합

    => 코드 1 의 수행시간은 n**2
    하지만 이전과 다른것은 i * j중 j > i
*/
/*
    제한사항
    MenOfPassion(A[], n) {
        sum <- 0;
        for i <- 1 to n - 1
            for j <- i + 1 to n
                sum <- sum + A[i] × A[j]; # 코드1
        return sum;
    }

    1 ≤ n ≤ 500,000
*/
#include <stdio.h>
#include <stdlib.h>

int MenOfPassion(int A[], int n) {
    int sum = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            sum += A[i] * A[j];
            cnt++;
        }
    }
    return cnt;
}
int main() {
    long long n;
    scanf("%lld", &n);

    int* A = malloc(n * sizeof(int));

    // printf("%lld\n%d\n", MenOfPassion(A, n), 2);    // 코드1의 수행 횟수와 최고차항의 차수를 출력
    printf("%lld\n%d\n", n * (n-1)/2, 2);  // 백준에 제출할땐 이거쓰세요
    return 0;
}
