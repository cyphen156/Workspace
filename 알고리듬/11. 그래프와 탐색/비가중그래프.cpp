#include <queue>
#include <vector>

using namespace std;

const int INF = 0x7fffffff;

int FindShrotestPath_Unweighted(int start,
                        int target = -1, 
                        const vector<vector<int>>& graph,
                        vector<int>& parent
                    )
{
    int V = graph.size();

    vector<int> dist(V, INF);
    parent.assign(V, -1);

    const bool hasTarget = ((target != -1) ? true : false);

    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        if (hasTarget && current == target)
        {
            return dist[current];
        }

        for (int i = 0; i < graph[current].size(); ++i)
        {
            int next = graph[current][i];

            if (dist[next] == INF)
            {
                dist[next] = dist[current] + 1;
                parent[next] = current;
                q.push(next);
            }
        }
    }
    if (hasTarget) 
    {
        return INF;
    }
    return 0;
}
