/**
 * 백준 플로이드_11404
 * N개의 도시와 M개의 경로가 있다.
 * 각 경로에는 필요 비용이 존재한다.
 * 모든 쌍에 대해서 A에서 B로 가는데 필요한 비용의 최솟값을 구하라.
 * 
 * 
 * 출력
 * n개의 줄을 출력해야 한다.
 * i번째 줄에 출력하는 j번째 숫자는 도시 i에서 j로 가는데 필요한 최소 비용이다.
 * 만약, i에서 j로 갈 수 없는 경우에는 그 자리에 0을 출력한다.
 * 
 * 
 * 제한사항
 *****************************************
 * 1<= N < 101                           *
 * 1 <= M < 100,001                      *
 * a is Start, b is End, c is Price      *
 * a != b                                *
 * 1 <= c < 100,001                      *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 3 + 20분
 */


#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int INF = 0x7fffffff;

static int N, M;

vector<vector<int>> dist;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    cin >> M;

    dist.assign(N + 1, vector<int>(N + 1, INF));

    // 자기 자신 처리
    for (int i = 1; i <= N; ++i)
    {
        dist[i][i] = 0;
    }
    
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;

        // 최소 거리만 저장하고 나머지 제외 
        // 동일 출발 - 목적지 경로 압축
        if (c < dist[a][b])
        {
            dist[a][b] = c;
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (dist[j][i] == INF)
            {
                continue;
            }
            for (int k = 1; k <= N; ++k)
            {
                if (dist[i][k] == INF)
                {
                    continue;
                }
                int candidate = dist[j][i] + dist[i][k];
                
                if (candidate < dist[j][k])
                {
                    dist[j][k] = candidate;
                }
            }
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (dist[i][j] == INF)
            {
                cout << 0;
            }
            else
            {
                cout << dist[i][j];    
            }
            cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}