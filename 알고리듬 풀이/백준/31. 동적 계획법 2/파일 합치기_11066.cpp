/**
 * 백준 파일 합치기_11066
 * 여러 개의 파일을 하나로 합쳐 하나의 파일로 만든다.
 * 한번 파일을 합칠때 두 개의 파일을 합칠 수 있다.
 * 최종적으로 필요한 비용(파일의 크기 합)을 계산하라.
 * 곰곰이 생각해보면 운영체제의 스케쥴링 문제와 비슷하다.
 * 파일의 파일을 합칠 수록 크기가 커지는데,
 * 합친 임시파일에 남은 파일을 추가로 합치므로,
 * 뒤에 합쳐지는 파일들은
 * 앞서 합쳐진 파일의 크기가 클 수록
 * 대기시간이 점점 더 커진다.
 * 
 * SJF와 비슷하다.
 * 다른 점은 
 * 파일의 순서를 바꿀 수 없다.
 * Ex) 조합 가능한 파일 합치는 순서의 예시
 * 1, 2, 3, 4
 * => ((1 + 2)+3)+4
 * => (1) + ((2 + 3) + 4)
 * => (1 + 2) + (3 + 4)
 * 
 * 제한사항
 *****************************************
 * Test T                                *
 * 3 <= K < 501                          *
 * 1 <= value < 10,001                   *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 5 + 60분
 */


#include <iostream>
#include <vector>

using namespace std;

static const int MAX_SIZE = 501;
static const long long INF = 0x7fffffffffffffff;

static int T, K;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    
    for (int i = 0; i < T; ++i)
    {
        cin >> K;
        
        long long prefix[MAX_SIZE] = { 0 };

        for (int j = 1; j <= K; ++j)
        {
            long long input;
            cin >> input;
            prefix[j] = prefix[j-1] + input;
        }

        static long long subSum[MAX_SIZE][MAX_SIZE];

        for (int j = 1; j <= K; ++j)
        {
            for (int k = 1; k <= K; ++k)
            {
                if (j == k)
                {
                    subSum[j][k] = 0;
                }
                else
                {
                    subSum[j][k] = INF;
                }
            }
        }


        for (int j = 2; j <= K; ++j)
        {
            int k = 1;
            while (k + j - 1 <= K)
            {
                int end = k + j - 1;

                for (int t = k; t < end; ++t)
                {
                    long long temp = subSum[k][t]
                                    + subSum[t+1][end]
                                    + (prefix[end]
                                        - prefix[k-1]);
                    if (temp < subSum[k][end])
                    {
                        subSum[k][end] = temp;
                    }
                }
                ++k;
            }
        }
        cout << subSum[1][K] << '\n';
    }
    return 0;
}