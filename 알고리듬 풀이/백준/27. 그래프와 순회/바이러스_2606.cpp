/**
 * 백준 바이러스_2606
 * 네트워크 전파에 관한 문제
 * 하나의 노드가 감염되면, 
 * 해당 노드와 연결된 다른 모든 노드에게 
 * 바이러스가 직, 간접 전파된다.
 * 
 * 제한사항
 *****************************************
 * 1 <= ComputerCount < 101              *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 1 + 20분
 */


#include <iostream>
#include <vector>
#include <queue>

static const int MAX_COMPUTER_COUNT = 101;

using namespace std;

struct Node 
{
    vector<int> isLinked;
};
static int computerCount, edgeCount;
static Node computer[MAX_COMPUTER_COUNT];
static bool isVisited[MAX_COMPUTER_COUNT] = { 0 };
static int cnt = 0;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> computerCount; 
    cin >> edgeCount;

    for (int i = 0; i < edgeCount; ++i)
    {
        int u, v;
        cin >> u >> v;
        computer[u].isLinked.push_back(v);
        computer[v].isLinked.push_back(u);
    }

    queue<int> q;
    q.push(1);
    isVisited[1] = true;

    while (q.empty() != true)
    {
        int u = q.front();
        q.pop();

        for (int i = 0; i < computer[u].isLinked.size(); ++i)
        {
            int v = computer[u].isLinked[i];

            if (isVisited[v] == false)
            {
                isVisited[v] = true;
                cnt++;
                q.push(v);
            }
        }
    }

    cout << cnt << '\n';
    return 0;
}