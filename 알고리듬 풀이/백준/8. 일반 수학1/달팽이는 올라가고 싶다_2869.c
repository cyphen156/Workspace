/*
처음에 작성한 반복연산 코드 
시간초과가 발생
==> 알고리즘의 변경이 필요함
===> 뺄셈연산이 아닌 나눗셈 연산으로 전환
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    int V, A, B, result = 0, i;
    
    scanf("%d %d %d", &A, &B, &V);

    for (i = 1; result <= V; i++) {
        result += A;
        if (result < V)
            result -= B;
        else
            break;
    }
    printf("%d", i);
    return 0;
}
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    int V, A, B, result;
    
    scanf("%d %d %d", &A, &B, &V);
    //  미끄러지지 않을 거리 - 나머지 발생시키기 / 실제 올라간 거리, 1일은 무조건 올라가기만함
    result = (V - B - 1) / (A - B) + 1; 
    printf("%d\n", result);
    return 0;
}

