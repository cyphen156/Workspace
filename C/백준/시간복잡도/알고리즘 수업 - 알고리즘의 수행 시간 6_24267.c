#define _CRT_SECURE_NO_WARNINGS
/*
    백준 24267 알고리즘 수업 - 알고리즘의 수행 시간 6
    반복횟수 = 중첩문
    ==> 선형복잡도 = O(n**3)
    이전과 다른것은 1 <= i < j < k <= n
*/
/*
    제한사항
    MenOfPassion(A[], n) {
        sum <- 0;
        for i <- 1 to n - 2
            for j <- i + 1 to n - 1
                for k <- j + 1 to n
                    sum <- sum + A[i] × A[j] × A[k]; # 코드1
        return sum;
    }

    1 ≤ n ≤ 500,000
*/
#include <stdio.h>
#include <stdlib.h>

int MenOfPassion(int A[], int n) {
    int sum = 0, cnt = 0;
    for (int i = 1; i <= n - 2; i++) {
        for (int j = i + 1; j <= n - 1; j++) {
            for (int k = j + 1; k <= n; k++) {
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

    //printf("%lld\n%d\n", MenOfPassion(A, n), 3);    // 코드1의 수행 횟수와 최고차항의 차수를 출력
    printf("%lld\n%d\n", n * (n - 1) * (n - 2) / 6, 3);// 백준 답안제출은 이걸로하세요
    return 0;
}
