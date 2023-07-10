#define _CRT_SECURE_NO_WARNINGS
// 백준 11653 소인수분해
#include <stdio.h>

int main() {
    // 1<= N <= 10,000,000, i
    int N, i = 2;
    scanf("%d", &N);
    // 무한반복 사용
    while (1) {
        
        // N이 1이면 아무것도 출력하지 않고 순회종료
        if (N == 1)
            break;
        
        // 약분이 되는 경우 나눈 수 저장하고 약수 초기화
        if (N % i == 0) {
            printf("%d\n", i);
            N = N / i;
            i = 2;
        }
        // 약분 안되면 인덱스 증가
        else 
            i++;
    }
    
    return 0;
}
