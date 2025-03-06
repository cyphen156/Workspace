#define _CRT_SECURE_NO_WARNINGS
/*
    백준 24313 알고리즘 수업 - 점근적 표기 1
    점근적 표기는 1부터 수행해서 무한히 수행해 나가다보면 
    결국 어떤 한 결론에 도달하지는 못하지만 무한히 가까워진다는걸 말한다.

    O(g(n)) = {f(n) | 모든 n ≥ n0에 대하여 
    f(n) ≤ c × g(n)인 양의 상수 c와 n0가 존재한다}
    f(n) = a1n + a0, 양의 정수 c, n0
    => a1n + a0 ≤ c × g(n)
    시간복잡도에서 최고차항을 제외한 나머지는 버린다
    -> (a1*n)/c <= g(n)
    예제 입력 1
    7 7
    8
    1
    예제 출력 1
    0
    ==> 7*1+7 = 8g(1)

    예제 입력 2
    7 7
    8
    10
    예제 출력 2
    1
    ==> 7*10+7 <= 8g(10)
*/
/*
    제한사항
    0 ≤ |ai| ≤ 100
    1 ≤ c ≤ 100
    1 ≤ n0 ≤ 100
*/
#include <stdio.h>

int value(int a1, int a0, int c, int n0) {
    int n;
    for (n = n0; n <= 10000; n++) {
        if (a1 * n + a0 > c * n) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int a1, a0;
    unsigned int c;
    unsigned int n0;
    scanf("%d %d", &a1, &a0);
    scanf("%u", &c);
    scanf("%u", &n0);

    printf("%d", value(a1, a0, c, n0));
    return 0;
}
