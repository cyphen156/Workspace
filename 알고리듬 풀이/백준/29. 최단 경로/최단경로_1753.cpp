/**
 * 백준 최단경로_1753
 * 방향 그래프가 주어졌을때 
 * 시작점에서 다른 모든 정점으로의 최단 경로를 구하라.
 * 
 * 
 * 제한사항
 *****************************************
 * 1 <= V < 20,001                       *
 * 1 <= E < 300,001                      *
 * 1 <= K < V+1                          *
 * from u to v                           *
 * 1 <= w < 11                           *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 5 + 20분
 */


#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

static const int MAX_VERTICIES_COUNT = 200001;
static const int MAX_EDGE_COUNT = 300001;
static const int INF = 1e9;

static int V, E, K;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;

    cin >> K;

    vector<vector<pair<int, int>>> graph(V + 1);
    vector<int> dist(V + 1, INF);
    dist[K] = 0;
    for (int i = 0; i < E; ++i)
    {
        int u, v, w;

        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({ 0, K });

    while (!pq.empty())
    {
        auto current = pq.top();
        pq.pop();

        
        int d = current.first;
        int u = current.second;

        if (d != dist[u]) 
        {
            continue;
        }

        for (int i = 0; i < (int)graph[u].size(); ++i)
        {
            int v = graph[u][i].first;
            int w = graph[u][i].second;

            if (dist[v] > d + w)
            {
                dist[v] = d + w;
                pq.push({ dist[v], v });
            }
        }
    }

    for (int i = 1; i <= V; ++i)
    {
        if (dist[i] == INF)
        {
            cout << "INF" << '\n';
        }
        else
        {
            cout << dist[i] << '\n';
        }
    }

    return 0;
}