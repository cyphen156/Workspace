/**
 * 백준 미확인 도착지_9370
 * 출발지는 아는데 목적지는 모른다.
 * 대신 목적지 후보군을 준다.
 * 최단 경로를 통해 후보군으로 이동 하는데 
 * 특정 경로를 반드시 지나가야 한다.
 * 가중 그래프를 통한 문제 풀이
 * 목적지 후보중 도착이 불가능한 경우 출력에서 제외한다.
 * 
 *
 * 제한사항
 *************************************************************
 * 2 <= n < 2,001 (교차로 == 정점)                            *
 * 1 <= m < 50,001 (도로 == 간선)                             *
 * 1 <= Test T < 101 (목적지 후보 == targets)                 *
 * 1 <= s, g, h < n (시작점, 특정경로 시작점, 특정경로 도착점)  *
 * 1 <= a, b, d < n (from a to b, weight is d)               *
 * 1 <= d < 1,001                                            *
 *************************************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 15 + 40분
 */


#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

static const int INF = 0x7fffffff;

static int T;
static int n, m, t;
static int s, g, h;
static int gh_w = 0;

static vector<vector<pair <int, int>>> graph;   
int Dijkstra(int start, int end);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        cin >> n >> m >> t;

        // 정점 생성
        graph.assign(n + 1, { });
        
        cin >> s >> g >> h;
        gh_w = -1;

        // 간선 입력
        for (int j = 0; j < m; ++j)
        {
            int a, b, d;
            cin >> a >> b >> d;
            graph[a].push_back({b, d});
            graph[b].push_back({a, d});

            if (((a == g) && (b == h)) ||
                ((a == h) && (b == g)))
            {
                gh_w = d;   
            }
        }

        vector<int> targets;
        // 목표지 테스트
        for (int j = 0; j < t; ++j)
        {
            int target;
            cin >> target;

            int minDist = Dijkstra(s, target);

            if (minDist == INF || gh_w < 0) 
            {
                continue;
            }

            int dist1 = Dijkstra(s, g); // s-> g
            dist1 += Dijkstra(h, target); // h-> t
            
            int dist2 = Dijkstra(s, h); // s-> h
            dist2 += Dijkstra(g, target); // g-> t
            
            int result = dist1;
            if (dist1 > dist2)
            {
                result = dist2;
            }
            result += gh_w; // g-> h (common)

            if (minDist == result)
            {
                targets.push_back(target);
            }
        }

        sort(targets.begin(), targets.end());

        for (int j = 0; j < targets.size(); ++j)
        {
            cout << targets[j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

int Dijkstra(int start, int end)
{
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        pair<int, int> current = pq.top(); 
        pq.pop();

        int cd = current.first;
        int u  = current.second;

        if (cd != dist[u])
        {
            continue;
        }
         if (u == end) 
        {
            return cd;
        }

        const vector<pair<int,int>>& adj = graph[u];
        for (size_t i = 0; i < adj.size(); ++i)
        {
            int v = adj[i].first;
            int w = adj[i].second;
            int nd = cd + w;
            if (nd < dist[v])
            {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }
    return dist[end];
}
