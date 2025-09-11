/**
 * 백준 운동_1956
 * V개의 마을과 E개의 도로
 * 방향 그래프, 목표에 갓다가 다시 시작점으로 돌아와야 한다.
 * 길이 합이 최소가 되도록해야한다.
 * 
 * 제한사항
 *****************************************
 * 2 <= V < 401                          *
 * 0 <= E < V(V - 1) + 1                 *
 * a is Start, b is End, c is price      *
 * 1 <= C < 10,001                       *
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

using namespace std;

const int INF = 0x7fffffff;

static int V, E;

vector<vector<int>> dist;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;

    dist.assign(V + 1, vector<int>(V + 1, INF));

    for (int i = 0; i < E; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (c < dist[a][b])
        {
            dist[a][b] = c;
        }    
    }
    
    for (int i = 0; i < V + 1; i++)
    {
        for (int j = 0; j < V + 1; j++)
        {
            if (dist[j][i] == INF)
            {
                continue;
            }
            for (int k = 0; k < V + 1; k++)
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

    int result = INF;

    for (int i = 1; i <= V; ++i)
    {
        for (int j = 1; j <= V; ++j)
        {
            if (i == j)
            {
                continue;
            }

            // 경로 없음
            if (dist[i][j] == INF || dist[j][i] == INF)
            {
                continue;
            }
            int cycle = dist[i][j] + dist[j][i];
            if (cycle < result)
            {
                result = cycle;
            }
        }
    }

    if (result == INF)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << result << '\n';
    }
    return 0;
}