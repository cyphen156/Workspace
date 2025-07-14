/**
 * 백준 별 찍기 - 10_2447
 * 재귀를 이용해 별찍자
 * N이 3의 거듭제곱(3, 9, 27, ...)이라고 할 때, 크기 N의 패턴은 N×N 정사각형 모양이다.
 * 크기 3의 패턴은 가운데에 공백이 있고, 가운데를 제외한 모든 칸에 별이 하나씩 있는 패턴이다.
 * ***
 * * *
 * ***
 * N이 3보다 클 경우, 크기 N의 패턴은 공백으로 채워진 가운데의 (N/3)×(N/3) 정사각형을 크기 N/3의 패턴으로 둘러싼 형태이다. 
 * Ex) 27 : 가운데 9 X 9 를 9의 패턴으로 둘러싼 형태
 * 9 : 가운데 3 X 3을 3의 패턴으로 둘러싼 형태 
 * 
 * 제한사항
 *****************************************
 * N = 3^K                               *
 * 1 <= K < 8                            *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 40분
 */


#include <iostream>
#include <cmath>

using namespace std;

char board[2187][2187];

void PrintStar(int startX, int startY, int size);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            board[i][j] = ' ';
        }
    }

    PrintStar(0, 0, N);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}

void PrintStar(int startX, int startY, int size)
{
    if (size == 1)
    {
        board[startX][startY] = '*';
        return;
    }

    int next = size / 3;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (i == 1 && j == 1)
            {
                continue;
            }
            PrintStar(startX + (j * next), startY + (i * next), next);
        }
    }
}