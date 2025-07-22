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
 * 없다.
 * 
 * 풀이시간 0분
 */

#include <iostream>

static bool isUsed[15][15] = { 0 };

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;

    int count = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (count == N)
            {
                break;
            }        
        }
    }
    return 0;
}