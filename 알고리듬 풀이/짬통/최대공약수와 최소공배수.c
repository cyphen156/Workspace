/**
* 백준 최대공약수와 최소공배수
* 
* 두 자연수의 최대 공약수와 최소공배수를 출력
* 
* 최대공약수를 알면 최소공배수도 쉽게 구할 수 있다.
* 
* ==> 큰 수(A)에서 작은 수(B)를 나눗셈 연산한다.
* 결과(A/B)를 다시 큰 수(A)로 나눗셈 연산한다.
* 나누어 떨어질 때까지 연산한다 (result == 0)
* ==> 최대 공약수
* 
* 최소 공배수 == A * B / result(최대공약수)
* 
* 제한사항
*****************************************
* 1 <= A, B <= 10,000					*
*****************************************
*
*
*
* 주의
* 
* 유클리드 호제법 사용하세요
* 
* 풀이시간 10분
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>

int main() {
    int A, B;
    
    scanf("%d%d", &A, &B);
    if (A < B) {
        int temp = A;
        A = B;
        B = temp;
    }

    int maxCommonDivisor = INT_MIN;
    int minCommonMulti = 1;

    int a = A, b = B;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    maxCommonDivisor = a;

    minCommonMulti = A * B / maxCommonDivisor;
    printf("%d\n%d", maxCommonDivisor, minCommonMulti);
    return 0;
}