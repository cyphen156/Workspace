/**
 * 백준 N-Queen_9663
 * N * N 크기의 체스판에 N개의 퀸이 서로 공격 할 수 없도록 놓는 문제
 * 생각해보면 퀸 하나가 배치되면 해당 행, 열에는 다시는 배치될 수 없다.
 * 대각선 칸으로도 배치될 수 없다.
 * 
 * 
 * 제한사항
 *****************************************
 * 0 < N < 15                            *
 *****************************************
 *
 *
 *
 * 주의
 * 수식을 적극적으로 사용하자 10초는 생각보다 짧다.
 * 반복문으로 대각선 조건체크할경우 시간복잡도가 O(N^3)이라서 무조건 Time Limit Exceeded 뜬다.
 * 
 * 풀이시간 30분
 */

#include <iostream>

static int N;
static int cnt = 0;

static int queenPosition[15] = { 0 };

bool IsValid(int row, int column);
void Backtrack(int row);

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    Backtrack(0);

    cout << cnt << '\n';
    return 0;
}

bool IsValid(int row, int column)
{
    for(int i = 0; i < row; ++i)
    {
        // 열 성분 체크
        // ==> 같은 열에 퀸이 존재해서는 안됨
        if (queenPosition[i] == column)
        {
            return false;
        }
        
        // 대각 성분 체크 
        // -x, -y 좌상단
        // ==> 행 인덱스를 늘려가며 퀸을 배치하므로 점검하지 않음 
        
        // +x, -y 우상단
        // ==> 행 인덱스를 늘려가며 퀸을 배치하므로 점검하지 않음
        
        // -x, +y 좌하단
        // int r = i;
        // int c = queenPosition[i];
        // while (r < N && c >= 0)
        // {
        //     r++;
        //     c--;
        //     if (r == row && c == column)
        //     {
        //         return false;
        //     }
        // }

        // // +x, +y 우하단    
        // r = i;
        // c = queenPosition[i];
        // while (r < N && c < N)
        // {
        //     r++;
        //     c++;
        //     if (r == row && c == column)
        //     {
        //         return false;
        //     }
        // }
        if (abs(queenPosition[i] - column) == row - i)
        {
            return false;
        }
    }

    return true;
}

void Backtrack(int row)
{
    // 행 끝까지 왔으니 퀸의 배치가 성공함
    if (row == N)
    {
        cnt++;
        return;
    }

    for (int i = 0; i < N; ++i)
    {
        if(!IsValid(row, i))
        {
            continue;
        }
        
        queenPosition[row] = i;
        Backtrack(row + 1);
    }
}