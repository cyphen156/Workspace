#include <queue>
#include <vector>

void BFS(int start, const std::vector<std::vector<int>>& g)
{
    std::queue<int> q;
    std::vector<bool> isVisited(g.size(), false);

    q.push(start);
    isVisited[start] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        
        for (int i = 0; i < g[current].size(); ++i)
        {
            int next = g[current][i];
            if (!isVisited[next])
            {
                isVisited[next] = true;
                q.push(next);
            }
        }
    }
}