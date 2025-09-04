/**
 * 백준 최종 순위_3665
 * N개의 팀에서 상대 순위만을 알려줄 때, 최종 순위를 추론하라.
 * 만약 목록에 없으면 해당 팀들 사이의 상대적 순위는 변하지 않는다
 * 
 *  출력
 * 1등 팀 부터 순서대로 출력
 * 확실한 순위를 찾을 수 없는 경우 : "?"
 * 데이터의 일관성이 없어서 순위를 정할 수 없는 경우 : "IMPOSSIBLE"
 * 
 * 
 * 제한사항
 *****************************************
 * 1 <= TEST T < 101                     *
 * 2 <= n < 501                          *
 * n is team Count                       *
 * 1 <= ti < n + 1                       *
 * 0 <= m < 25,001                       *
 * m is compairCase                      *
 * 1 ≤ ai < bi ≤ n                       *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 5 + 120분
 */


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static const int MAX_TEAM_COUNT = 501;
static const int MAX_COMPAIR_CASE_COUNT = 25001;

static int T, n, m;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        // team count
        cin >> n;

        // index is teamNo value is rank
        vector<int> lastYearRank(n + 1, 0);   
        vector<int> teamAt(n + 1, 0);
         
        for (int j = 1; j <= n; ++j)
        {
            int teamNumber;
            cin >> teamNumber;
            lastYearRank[teamNumber] = j;
        }

        for (int j = 1; j <= n; ++j)
        {
            teamAt[lastYearRank[j]] = j;
        }

        // 그래프 구성하기
        vector<vector<bool>> has(n + 1, vector<bool>(n + 1, false));

        for (int j = 1; j <= n; ++j)
        {
            int u = teamAt[j];
            for (int k = j + 1; k <= n; ++k)
            {
                int v = teamAt[k];
                has[u][v] = true; // u -> v
            }
        }

        // compair case
        cin >> m;
        for (int j = 0; j < m; ++j)
        {
            int a, b;
            cin >> a >> b;

            if (has[a][b])
            {
                has[a][b] = false;
                has[b][a] = true;
            }
            else
            {
                has[b][a] = false;
                has[a][b] = true;
            }
        }

         vector<int> inDegree(n + 1, 0);
        for (int j = 1; j <= n; ++j)
        {
            int deg = 0;
            for (int k = 1; k <= n; ++k)
            {
                if (has[k][j])
                {
                    ++deg;
                }
            }
            inDegree[j] = deg;
        }

        queue<int> q;
        for (int j = 1; j <= n; ++j)
        {
            if (inDegree[j] == 0)
            {
                q.push(j);
            }
        }

        vector<int> result;
        result.reserve(n);
        bool ambiguous = false;
        bool impossible = false;

        for (int j = 0; j < n; ++j)
        {
            if (q.empty())
            {
                impossible = true;
                break;
            }
            if ((int)q.size() > 1)
            {
                ambiguous = true;
            }

            int u = q.front();
            q.pop();
            result.push_back(u);

            // u의 모든 후속 정점 처리 (행 스캔)
            for (int k = 1; k <= n; ++k)
            {
                if (has[u][k])
                {
                    has[u][k] = false;
                    if (--inDegree[k] == 0)
                    {
                        q.push(k);
                    }
                }
            }
        }

        if (impossible)
        {
            cout << "IMPOSSIBLE\n";
        }
        else if (ambiguous)
        {
            cout << "?\n";
        }
        else
        {
            for (int j = 0; j < n; ++j)
            {
                if (j)
                {
                    cout << ' ';
                }
                cout << result[j];
            }
            cout << '\n';
        }
    }


    return 0;
}