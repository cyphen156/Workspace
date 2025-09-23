/**
 * 백준 내리막 길_1520
 * 시작점부터 목표 위치까지 이동할 수 있는 경로의 수를 구하라.
 * 상하좌우로 움직일 수 있지만, 
 * 이동할 때 항상 현재보다 더 낮은 비용의 위치로만 이동할 수 있다.
 * 
 * 제한사항
 *****************************************
 * 1 <= M, N < 501                       *
 * 1 <= H < 10,001                       *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 3 + 60분
 */


#include <iostream>
#include <stack>
#include <utility>

using namespace std;

static const int MAX_SIZE = 501;

static int M, N;
static int matrix[MAX_SIZE][MAX_SIZE];
static int pathCount[MAX_SIZE][MAX_SIZE];
static char state[MAX_SIZE][MAX_SIZE]; 

static int dy[4] = {-1, 1, 0, 0};
static int dx[4] = {0, 0, -1, 1};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> M >> N;

    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> matrix[i][j];
            pathCount[i][j] = -1;   // initialize
            state[i][j] = 0;
        }
    }

    stack<pair<int, int>> st;
    st.push({ 0, 0 });

    pair<int, int> target = {M - 1, N - 1};
    while (!st.empty())
    {
        pair<int, int> current = st.top();
        int row = current.first;
        int column = current.second;

        if (state[row][column] == 0)
        {
            state[row][column] = 1;

            for (int i = 0; i < 4; ++i)
            {
                int ny = current.first + dy[i];
                int nx = current.second + dx[i];

                // 경계 밖 좌표이동 처리
                if (ny < 0 || ny >= M ||
                    nx < 0 || nx >= N)
                {
                    continue;
                }
                
                if (matrix[ny][nx] < matrix[row][column] && state[ny][nx] == 0)
                {
                    st.push({ ny, nx });
                }
            }
        }

        else if (state[row][column] == 1)
        {
            if (row == M - 1 && column == N - 1)
            {
                pathCount[row][column] = 1;
            }
            else
            {
                long long sum = 0;

                for (int i = 0; i < 4; ++i)
                {
                    int ny = row + dy[i];
                    int nx = column + dx[i];

                    if (ny < 0 || ny >= M || nx < 0 || nx >= N)
                    {
                        continue;
                    }

                    if (matrix[ny][nx] < matrix[row][column])
                    {
                        if (pathCount[ny][nx] != -1)
                        {
                            sum += pathCount[ny][nx];
                        }
                    }
                }

                pathCount[row][column] = static_cast<int>(sum);
            }
            
            state[row][column] = -1;
            st.pop();
        }
        else 
        {
            st.pop();
        }
    }
    cout << pathCount[0][0] << '\n';
    return 0;
}