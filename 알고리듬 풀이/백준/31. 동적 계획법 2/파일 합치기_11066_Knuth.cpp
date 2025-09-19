#include <iostream>
using namespace std;

static const int MAX_SIZE = 501;                  // K ≤ 500
static const long long INF = 0x7fffffffffffffff;  // 매우 큰 값

static int T, K;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for (int _tc = 0; _tc < T; ++_tc)
    {
        cin >> K;

        static long long prefix[MAX_SIZE];
        static long long subSum[MAX_SIZE][MAX_SIZE];
        static int split[MAX_SIZE][MAX_SIZE];

        // 입력 + 누적합(1-based)
        prefix[0] = 0;
        for (int i = 1; i <= K; ++i)
        {
            long long x;
            cin >> x;
            prefix[i] = prefix[i - 1] + x;
        }

        // 초기화
        for (int i = 1; i <= K; ++i)
        {
            for (int j = 1; j <= K; ++j)
            {
                if (i == j)
                {
                    subSum[i][j] = 0;
                    split[i][j] = i;
                }
                else
                {
                    subSum[i][j] = INF;
                    split[i][j] = 0;
                }
            }
        }

        // Knuth 최적화: 길이 j, 시작 k, 끝 i = k + j - 1, 분할점 t
        for (int j = 2; j <= K; ++j)            // j: 구간 길이
        {
            for (int k = 1; k + j - 1 <= K; ++k) // k: 구간 시작
            {
                int i = k + j - 1;              // i: 구간 끝

                // 탐색 범위: [split[k][i-1], split[k+1][i]] 로 제한
                int L = split[k][i - 1];
                int R = split[k + 1][i];

                if (L < k)
                {
                    L = k;
                }
                if (R > i - 1)
                {
                    R = i - 1;
                }
                if (L > R)
                {
                    int tmp = L;
                    L = R;
                    R = tmp;
                }

                long long best = INF;
                int best_t = L;

                for (int t = L; t <= R; ++t)    // t: 분할점
                {
                    long long cost =
                        subSum[k][t] +
                        subSum[t + 1][i] +
                        (prefix[i] - prefix[k - 1]);

                    if (cost < best)
                    {
                        best = cost;
                        best_t = t;
                    }
                }

                subSum[k][i] = best;
                split[k][i] = best_t;
            }
        }

        cout << subSum[1][K] << '\n';
    }

    return 0;
}
