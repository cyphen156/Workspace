/**
 * 백준 행렬 곱셈 순서_11049
 * N X M 크기의 행렬과 M X K크기의 행렬 B를 고하면 연산수는 
 * N X M X K번이다.
 * 여러개의 행렬이 주어졋을 때 
 * 모든 행렬을 곱하는데 필요한 곱셈 연산 횟수를 
 * 최소로 만드는 프로그램을 구하라. 
 * 단, 행렬의 순서는 변경할 수 없다.
 * 게임수학적 지식, 행렬 곱을 통한 연산횟수 축소 기법 
 * 행렬의 연산 횟수를 줄이려면 
 * N * M의 크기가  계속해서 줄어드는 것을 선택하는것이 좋다
 * ==> M의 크기가 작을 수록 좋다.
 * 
 * 제한사항
 *****************************************
 * 1 <= N < 501                          *
 * 1 <= r, c < 501                       *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 3 + 60분
 */


#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const static long long INF = 0x7fffffffffffffff;

static int N;
vector<pair<int, int>> matrices;
vector<vector<long long>> counts;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    matrices.resize(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> matrices[i].first >> matrices[i].second;
    }

    counts.assign(N, vector<long long>(N, INF));

    // 자기자신 비용 처리
    for (int i = 0; i < N; ++i)
    {
        counts[i][i] = 0;
    }

    for (int length = 2; length <= N; ++length)
    {
        for (int start = 0; start + length - 1 < N; ++start)
        {
            int end = start + length - 1;

            for (int mid = start; mid < end; ++mid)
            {
                long long leftCost  = counts[start][mid];
                long long rightCost = counts[mid + 1][end];
                long long mergeCost = 1LL * matrices[start].first
                                           * matrices[mid].second
                                           * matrices[end].second;
                long long cand      = leftCost + rightCost + mergeCost;

                if (cand < counts[start][end])
                {
                    counts[start][end] = cand;
                }
            }
        }
    }

    cout << counts[0][N - 1] << '\n';
    return 0;
    return 0;
}