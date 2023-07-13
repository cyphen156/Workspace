#define _CRT_SECURE_NO_WARNINGS
/*
    백준 24264 알고리즘 수업 - 알고리즘의 수행 시간 3
    ⌊ ⌋ 이건 뭔가 싶었는데 바닥함수랜다 
    -> 정수의 나눗셈을 통해 소숫점을 버리는 연산
    인자로 배열과 배열의 길이?를 받고 그 배열의 중간 값(인덱스 n/2)을 리턴
    -> 함수가 한번만 실행됨 -> 항상 출력이 1(상수)
*/ 
/*
    제한사항
    MenOfPassion(A[], n) {
    i =  ⌊ n / 2 ⌋;
    return A[i]; # 코드1
    }

    1 ≤ n ≤ 500,000
*/
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    printf("1\n0\n");    // 코드1의 수행 횟수와 최고차항의 차수를 출력
    return 0;
}
