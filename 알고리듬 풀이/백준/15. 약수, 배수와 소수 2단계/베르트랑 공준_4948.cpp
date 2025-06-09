/**
 * 백준 베르트랑 공준_4948
 * 임의의 자연수 N에 대해 N보다 크고, 2N보다 작거나 같은 소수는 적어도 하나 존재한다.
 * N < PrimeNumber <= 2N
 * 앞서 푼 문제였던 소수 구하기의 응용버전
 * 조금 다르게 갯수를 출력한다.
 * 
 * 제한사항
 *****************************************
 * 1 ≤  N ≤ 123,456                      *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 10분
 */

#include <iostream>

using namespace std;

#define MAXSIZE 123456

static bool isNotPrime[(MAXSIZE * 2) + 1];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    isNotPrime[0] = isNotPrime[1] = true;

    for (int i = 2; i * i <= 2 * MAXSIZE; ++i)
    {
        // 현재 소수라고 마스킹 되어 있다면
        if (!isNotPrime[i])
        {
            // 곱한수는 모두 합성수 처리
            for (int j = i * i; j <= 2 * MAXSIZE; j += i)
            {
                isNotPrime[j] = true;
            }
        }
    }
        
    while (true)
    {
        int N;
    
        cin >> N;
    
        if (N == 0)
        {
            break;
        }
        
        int count = 0;

        for (int i = N+1; i < (2 * N) + 1; ++i)
        {
            if (!isNotPrime[i])
            {
                count++;
            }
        }
        cout << count << '\n';
    }
    return 0;
}