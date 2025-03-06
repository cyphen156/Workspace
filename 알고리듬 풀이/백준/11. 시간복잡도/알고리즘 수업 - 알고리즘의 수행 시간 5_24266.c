#define _CRT_SECURE_NO_WARNINGS
/*
    백준 24266 알고리즘 수업 - 알고리즘의 수행 시간 5
    반복횟수 = 중첩for문
    
    => 코드 1 의 수행시간은 n**3
*/
/*
    제한사항
    MenOfPassion(A[], n) {
        sum <- 0;
        for i <- 1 to n
            for j <- 1 to n
                for k <- 1 to n
                    sum <- sum + A[i] × A[j] × A[k]; # 코드1
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
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                sum += A[i] * A[j] * A[k];
                cnt++;
            }
        }
    }
    return cnt;
}
int main() {
    long long n;
    scanf("%lld", &n);

    int* A = malloc(n * sizeof(int));

    printf("%lld\n%d\n", n * n *n, 3);    // 코드1의 수행 횟수와 최고차항의 차수를 출력
    return 0;
}
