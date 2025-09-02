/**
 * 백준 단지번호붙이기_2667
 * 이차원 행렬을 통한 인접리스트 탐색하기
 * 
 * 제한사항
 *****************************************
 * 5 <= N < 26                           *
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
#include <queue>
#include <vector>
#include <algorithm>

const int MAX_SIZE = 26;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

using namespace std;

static int N;

static char matrix[MAX_SIZE][MAX_SIZE] = { 0 };
static bool isVisited[MAX_SIZE][MAX_SIZE] = { 0 };

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            char ch;
            cin >> ch;
            matrix[i][j] = ch;
        }        
    }

    int cnt = 0;
    vector<int> town;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            // 새 단지 찾음
            if (isVisited[i][j] == false && matrix[i][j] == '1') 
            {
                cnt++;
                // 단지 구성 (BFS)
                int houseCount = 0;
                queue<pair<int, int>> q;
                q.push({i, j});
                isVisited[i][j] = true;

                while (q.empty() != true)
                {
                    pair<int, int> current = q.front();
                    q.pop();
                    houseCount++;

                    for (int k = 0; k < 4; ++k)
                    {
                        int ny = current.first  + dy[k];
                        int nx = current.second + dx[k];

                        if (ny < 0 || ny >= N || nx < 0 || nx >= N) 
                        { 
                            continue; 
                        }

                        if (matrix[ny][nx] != '1') 
                        { 
                            continue; 
                        }

                        if (isVisited[ny][nx]) 
                        { 
                            continue; 
                        }

                        isVisited[ny][nx] = true;
                        q.push({ny, nx});
                    }
                }

                town.push_back(houseCount);
            }
        }
    }    

    cout << cnt << '\n';

    sort(town.begin(), town.end());

    for (int v : town)
    {
        cout << v << '\n';
    }

    return 0;
}