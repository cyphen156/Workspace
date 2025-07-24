/**
 * 백준 알고리즘 수업 - 피보나치 수 1_24416
 * 재귀 호출을 하되 이미 연산된 결과를 저장하는 배열을 사용하여 중복 연산을 스킵한다.
 * 동적이라고 하지만 전혀 동적이지 않은 알고리즘이다. 
 * 재귀 호출식과 메모이제이션의 수행 횟수를 비교할 수 있도록 연산 횟수를 출력하라.
 * 정적 계획법 또는 메모리 재활용하기라고 호칭 좀 바꾸자
 * 의사 코드는 다음과 같다.
 * 
 * fib(n) {
 *     if (n = 1 or n = 2)
 *     then return 1;  # 코드1
 *     else return (fib(n - 1) + fib(n - 2));
 * }
 * 
 * fibonacci(n) {
 *     f[1] <- f[2] <- 1;
 *     for i <- 3 to n
 *         f[i] <- f[i - 1] + f[i - 2];  # 코드2
 *     return f[n];
 * }
 * 
 * 
 * 제한사항
 *****************************************
 * 4 < N <= 40                           *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 5 + 5분
 */


#include <iostream>

static int f[40];
static int callCount = 0;
static int callCount2 = 0;

int fib(int n);
int fibonacci(int n);

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n; 
    cin >> n;
    fib(n);
    fibonacci(n);
    
    cout << callCount << ' ' <<  callCount2 << '\n';

    return 0;
}

int fib(int n) 
{
    if (n == 1 || n == 2)
    {
        callCount++;
        return 1;
    }

    return (fib(n - 1) + fib(n - 2));
}

int fibonacci(int n)
{
    f[1] = f[2] = 1;
    callCount2++;

    for (int i = 3; i < n; ++i)
    {
        f[i] = f[i - 1] + f[i - 2];
        callCount2++;
    }

    return f[n];
}