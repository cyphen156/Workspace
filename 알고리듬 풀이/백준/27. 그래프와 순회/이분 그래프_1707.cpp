/**
 * 백준 이분 그래프_1707
 * 그래프가 이진그래프인지 아닌지 판단해라.
 * 그림 이해가 잘 안될 수 있으니 위키피다이 그림 확인하기
 * Hint)
 * "정점들을 두 개의 그룹으로 분할한다."
 * => 갯수는 니 맘대로 해봐라
 * 그리고 같은 그룹 안의 정점끼리의 간선 관계가 존재하지 않는다면 된다.
 * ==> 그룹을 나누었을 때 그 그룹 안의 간선관계가 존재하는지만 판단하면 
 * 다른그룹과의 간선관계는 관심 없다.
 * 체스, 바둑에서 아이디어를 가져온다.
 * => 이진 색상 판별
 * 
 * 제한사항
 *****************************************
 * TEST K                                *
 * V is Verticies                        *
 * E is Edge                             *
 * 2 <= K < 6                            *
 * 1 <= V <20,001                        *
 * 1 <= E <200,001                       *
 * If (Bipartite Graph) Then "YES"       *
 * else Then "NO"                        *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 15 + 30분
 */


#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

static const int MAX_VERTICIES_COUNT = 20001;
static const int MAX_EDGE_COUNT = 200001;

static int K, V, E;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> K;

    for (int i = 0; i < K; ++i)
    {
        cin >> V >> E;

        vector<vector<int>> verticies(V + 1);

        bool isBipartiteGraph = true;

        for (int j = 0; j < E; ++j)
        {
            int u, v;
            cin >> u >> v;
            verticies[u].push_back(v);
            verticies[v].push_back(u);
        }

        queue<int> q;
        vector<int> color(V + 1, 0); 

        // 분할 그래프 평가 시작
        for (int j = 1; j <= V && isBipartiteGraph; ++j)
        {
            if (color[j] != 0)
            {
                continue;
            }

            color[j] = 1;
            q.push(j);

            while (!q.empty() && isBipartiteGraph)
            {
                int current = q.front();
                q.pop();
                for (int k = 0; k < verticies[current].size(); ++k)
                {
                    int v = verticies[current][k];

                    if (color[v] == 0)
                    {
                        // 다른 색상
                        color[v] = -color[current];
                        q.push(v);
                    }
                    else if (color[v] == color[current])
                    {
                        isBipartiteGraph = false;
                        break;
                    }
                }
            }
        }
        cout << (isBipartiteGraph ? "YES" : "NO") << '\n';
    }
    return 0;
}