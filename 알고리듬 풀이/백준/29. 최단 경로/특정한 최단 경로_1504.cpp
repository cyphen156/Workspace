/**
 * 백준 특정한 최단 경로_1504
 * 방향 그래프가 주어졌을때 시작점에서 한 정점으로의 최단 경로를 구하라.
 * 단, 임의로 주어진 두 정점을 반드시 통과해야 한다.
 * 이미 방문한 정점을 다시 방문할 수 있다.
 * 만약 경로가 없다면 -1을 출력한다.
 * 
 * 
 * 제한사항
 *****************************************
 * 1 <= N < 801                          *
 * 1 <= E < 200,001                      *
 * start at 1, End at N                  *
 * from a to b                           *
 * 1 <= c < 1,001                        *
 * v1 != v2                              *
 * v1 != N                               *
 * v2 != 1                               *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 5 + 30분
 */


#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

static const int MAX_VERTICIES_COUNT = 801;
static const int MAX_EDGE_COUNT = 200001;
static const int INF = 0x7fffffff;

static int N, E;
static int v1, v2;

vector<vector<pair<int, int>>> graph;

int dijkstra(int from, int to);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> E;
    graph.assign(N + 1, {});

    for (int i = 0; i < E; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }

    cin >> v1 >> v2;

    long long dist = dijkstra(v1, v2);      // v1-> v2 == v2-> v1
    
    long long case1 = dijkstra(1, v1);      // 1->v1->v2->N
    case1 += dijkstra(v2, N);
    
    long long case2 = dijkstra(1, v2);      // 1->v2->v1->N
    case2 += dijkstra(v1, N);

    if (case1 <= case2)
    {
        dist += case1;
    }
    else
    {
        dist += case2;
    }

    if (dist >= INF) 
    {
        cout << -1 << '\n';
        return 0;
    }
    cout << dist << '\n';
    return 0;
}

int dijkstra(int from, int to)
{
    vector<int> dist(N + 1, INF);
    dist[from] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, from});

    while (!pq.empty())
    {
        auto cur = pq.top(); 
        pq.pop();
        int d = cur.first;
        int u = cur.second;

        if (d != dist[u]) 
        { 
            continue; 
        } 
        if (u == to) 
        { 
            break; 
        } 

        for (const auto& e : graph[u])
        {
            int v = e.first;
            int w = e.second;

            if (dist[v] > d + w)
            {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[to];
}