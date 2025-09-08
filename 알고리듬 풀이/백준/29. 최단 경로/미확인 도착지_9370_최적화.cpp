/**
 * 백준 미확인 도착지_9370 — 3 다익스트라 최적화 풀이
 */

#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

static const int INF = 0x7fffffff;

static int T;
static int n, m, t;
static int s, g, h;
static int gh_w = -1;

static vector<vector<pair<int, int> > > graph;

vector<int> DijkstraAll(int start)
{
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int> > > pq;

    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        pair<int,int> current = pq.top(); pq.pop();
        int cd = current.first;
        int u  = current.second;

        if (cd != dist[u]) continue;

        const vector<pair<int,int> >& adj = graph[u];
        for (size_t i = 0; i < adj.size(); ++i)
        {
            int v = adj[i].first;
            int w = adj[i].second;
            if (cd + w < dist[v])
            {
                dist[v] = cd + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int tc = 0; tc < T; ++tc)
    {
        cin >> n >> m >> t;

        graph.assign(n + 1, vector<pair<int,int> >());
        cin >> s >> g >> h;
        gh_w = -1;

        for (int i = 0; i < m; ++i)
        {
            int a, b, d;
            cin >> a >> b >> d;
            graph[a].push_back(make_pair(b, d));
            graph[b].push_back(make_pair(a, d));
            if (((a == g) && (b == h)) || ((a == h) && (b == g))) gh_w = d;
        }

        vector<int> cand(t);
        for (int i = 0; i < t; ++i) { int x; cin >> x; cand[i] = x; }
        sort(cand.begin(), cand.end());

        vector<int> distS = DijkstraAll(s);
        vector<int> distG = DijkstraAll(g);
        vector<int> distH = DijkstraAll(h);

        vector<int> targets;
        targets.reserve(t);

        for (int i = 0; i < t; ++i)
        {
            int target = cand[i];
            if (gh_w < 0) continue;
            if (distS[target] == INF) continue;

            long long case1 = (long long)distS[g] + (long long)gh_w + (long long)distH[target];
            long long case2 = (long long)distS[h] + (long long)gh_w + (long long)distG[target];

            if ((long long)distS[target] == case1 || (long long)distS[target] == case2)
            {
                targets.push_back(target);
            }
        }

        for (int i = 0; i < (int)targets.size(); ++i) cout << targets[i] << ' ';
        cout << '\n';
    }
    return 0;
}
