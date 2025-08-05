/**
 * 백준 동전 0_11047
 * N종류의 동전을 사용해 가치 K를 만드는데 
 * 사용된 동전의  개수를 최소한으로 구하는 프로그램을 작성한다.
 * 
 * 제한사항
 *****************************************
 * 1 <= N < 11                           *
 * 1 <= K < 100,000,001                  *
 * 1 ≤ Ai < 1,000,001                    *
 * A1 = 1                                *
 * i ≥ 2인 경우, Ai는 Ai-1의 배수         *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 1 + 5분
 */


#include <iostream>

#define MAX_SIZE 11
#define MAX_VALUE 100000001

using namespace std;

static int coins[MAX_SIZE] = { 1 };
static int N, K;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        cin >> coins[i];
    }

    int cnt = 0;

    // int currentIDX = N - 1;
    // while (K != 0)
    // {
    //     int temp = K - coins[currentIDX];

    //     if (temp < 0)
    //     {
    //         currentIDX--;
    //     }
    //     else 
    //     {
    //         K -= coins[currentIDX];
    //         cnt++;
    //     }
    // }

    for (int i = N - 1; i >= 0; --i) 
    {
        cnt += K / coins[i];
        K %= coins[i];
    }

    cout << cnt << '\n';
    return 0;
}