/**
 * 백준 소수 구하기_1929
 * 에라토스테네스의 체를 사용하여 M 이상 N이하의 모든 소수 구하기
 * 
 * 제한사항
 *****************************************
 * 1 ≤ M ≤ N ≤ 1,000,000                 *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 20분
 */


#include <iostream>

using namespace std;

static bool isNotPrime[1000001] = { 0 };

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int M, N;

    cin >> M >> N;

    isNotPrime[0] = isNotPrime[1] = true;

    for (int i = 2; i * i <= N; ++i)
    {
        // 현재 소수라고 마스킹 되어 있다면
        if (!isNotPrime[i])
        {
            // 곱한수는 모두 합성수 처리
            for (int j = i * i; j <= N; j += i)
            {
                isNotPrime[j] = true;
            }
        }
        
    }

    for (int i = 0; i < N + 1; ++i)
    {
        // 현재 인덱스를 감지해서 출력하기 M <= Cout <= N
        if (i < M)
        {
            continue;
        }

        if (!isNotPrime[i])
        {
            cout << i << '\n';
        }
    }
    return 0;
}