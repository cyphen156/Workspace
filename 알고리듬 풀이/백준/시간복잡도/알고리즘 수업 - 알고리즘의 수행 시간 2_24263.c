#define _CRT_SECURE_NO_WARNINGS
/*
    백준 24263 알고리즘 수업 - 알고리즘의 수행 시간 2
    반복횟수 = 입력 값
    ==> 선형복잡도 = O(n)
*/ 
/*
    제한사항
    MenOfPassion(A[], n) {
    sum <- 0;
    for i <- 1 to n
        sum <- sum + A[i]; # 코드1
    return sum;
    }

    1 ≤ n ≤ 500,000
*/
#include <stdio.h>
#include <stdlib.h>

int MenOfPassion(int A[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
    }
    return sum;
}
int main() {
    int n;
    scanf("%d", &n);
    
    int *A = malloc(n * sizeof(int));

    printf("%d\n%d\n", n, 1);    // 코드1의 수행 횟수와 최고차항의 차수를 출력
    return 0;
}
