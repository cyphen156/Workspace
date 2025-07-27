/**
 * 백준 쉬운 계단 수_10844
 * 인접한 모든 자리의 차이가 1일 때 계단 수라고 부른다.
 * Ex) 45678, 4545654
 * 부분 계단 수를 구하라. 만약 0으로 시작하는 부분 계단 수가 나온다면 제외한다. (01234 => 1234)
 * 출력부분을 주의한다. 
 * 
 * 제한사항
 *****************************************
 * 0 < N <= 100                          *
 *****************************************
 *
 *
 *
 * 주의
 * 정답을 1,000,000,000으로 나눈 나머지를 출력하라.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 3 + 60분
 */


#include <iostream>

#define MAX_SIZE    101
#define DIGIT       10   // 0 ~ 9
#define MOD         1000000000  
using namespace std;

                        //   Length   0 ~ 9
static int memoizationArray[MAX_SIZE][DIGIT] = { 0 };

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    // 한자리수는 항상 하나
    for (int i = 1; i <= 9; ++i) 
    {
        memoizationArray[1][i] = 1;
    }

    for (int i = 2; i <= N; ++i)
    {
        for (int j = 0; j < DIGIT; ++j)
        {
            // j - 1에서 올라오는 경우
            if (j > 0)
            {
                memoizationArray[i][j] += memoizationArray[i - 1][j - 1];
            }

            // j + 1에서 내려오는 경우
            if (j < 9)
            {
                memoizationArray[i][j] += memoizationArray[i - 1][j + 1];
            }

            memoizationArray[i][j] %= MOD;
        }
    }

    int result = 0;

    for (int j = 0; j < DIGIT; ++j)
    {
        result = (result + memoizationArray[N][j]) % MOD;
    }

    cout << result << '\n';

    return 0;
}