#define _CRT_SECURE_NO_WARNINGS
/*
    백준 24264 알고리즘 수업 - 알고리즘의 수행 시간 3
    반복횟수 = 중첩for문
    => 코드 1 의 수행시간은 n**2
*/
/*
    제한사항
    MenOfPassion(A[], n) {
        sum <- 0;
        for i <- 1 to n
            for j <- 1 to n
                sum <- sum + A[i] × A[j]; # 코드1
        return sum;
    }
    1 ≤ n ≤ 500,000
*/
#include <stdio.h>
#include <stdlib.h>

int MenOfPassion(int A[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += A[i] * A[j];
        }
    }
    return sum;
}
int main() {
    long long n;
    scanf("%lld", &n);

    int* A = malloc(n * sizeof(int));

    printf("%lld\n%d\n", n * n, 2);    // 코드1의 수행 횟수와 최고차항의 차수를 출력
    return 0;
}
