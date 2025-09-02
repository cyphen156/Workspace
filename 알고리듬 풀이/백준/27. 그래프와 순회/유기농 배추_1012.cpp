/**
 * 백준 유기농 배추_1012
 * 이전 문제와 비슷하다. 
 * 행렬을 사용하여 사방 탐색을 통해 형성된 단지 수를 세면 된다.
 * 
 * 제한사항
 *****************************************
 * TEST T                                *
 * 1 <= N < 51 (Column)                  *
 * 1 <= M < 51 (Row)                     *
 * 1 <= K < 2501                         *
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
#include <stack>

const static int MAX_SIZE = 50;
const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1};

using namespace std;

static int T, N, M, K;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        cin >> N >> M >> K;
        
        // 행렬 초기화
        int matrix[MAX_SIZE][MAX_SIZE] = { 0 };
        bool isVisited[MAX_SIZE][MAX_SIZE] = { 0 };
        
        int cnt = 0;

        for (int j = 0; j < K; ++j)
        {
            int row, column;
            cin >> row >> column;

            matrix[column][row] = 1;
        }
            
        for (int row = 0; row < M; ++row)
        {
            for (int column = 0; column < N; ++column)
            {
                if (matrix[row][column] == 1 && isVisited[row][column] == false)
                {
                    
                    cnt++;
                    stack<pair<int, int>> stack;
                    
                    stack.push({row, column});
                    isVisited[row][column] = true;
                    
                    while (stack.empty() != true)
                    {
                        pair<int, int> current = stack.top();
                        stack.pop();

                        for (int k = 0; k < 4; ++k)
                        {
                            int ny = current.first + dy[k];
                            int nx = current.second + dx[k];

                            if (ny < 0 || ny >= M || nx < 0 || nx >= N)
                            {
                                continue;
                            }
                            if (matrix[ny][nx] == 0)
                            {
                                continue;
                            }
                            if (isVisited[ny][nx])
                            {
                                continue;
                            }

                            isVisited[ny][nx] = true;
                            stack.push({ny, nx});
                        }
                    }
                }
            }
        }

        cout << cnt << '\n';
    }

   
    return 0;
}