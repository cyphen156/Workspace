/**
 * 백준 스도쿠_2580
 * 스도쿠는 다음과 같은 규칙이 존재한다.
 * 각각의 가로줄과 세로줄에는 1부터 9까지의 숫자가 한 번씩만 나타나야 한다.
 * 굵은 선으로 구분되어 있는 3x3 정사각형 안에도 1부터 9까지의 숫자가 한 번씩만 나타나야 한다.
 * 보드에 쓰여있는 숫자들에 대한 정보가 주어질 때 모든 빈칸이 채워진 최종 모습을 출력하는 프로그램을 작성하라.
 * Hint
 * 숫자 정보가 추가되어서 그렇지 N - Queen문제와 유사하다.
 * 
 * 제한사항
 ********************************************************
 * 입력값이 0이면 빈칸임을 의미한다.                       *
 * 12095번 문제에 있는 소스로 풀 수 있는 입력만 주어진다.   *
 *      C++14: 80ms                                     *
 *      Java: 292ms                                     *
 *      PyPy3: 1172ms                                   *
 ********************************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 30분
 */


#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

static int board[9][9] = { 0 };
static vector<pair<int, int>> check;

bool IsValid(int row, int column, int value);
void BackTrack(int index);


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력부
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cin >> board[i][j];

            if (board[i][j] == 0)
            {
                check.push_back({ i, j });
            }
        }   
    }

    // 빈칸채우기
    BackTrack(0);

    return 0;
}

bool IsValid(int row, int column, int value)
{
    // 행검사
    for (int i = 0; i < 9; ++i)
    {
        if (board[row][i] == value)
        {
            return false;
        }
    }
    // 열검사
    for (int i = 0; i < 9; ++i)
    {
        if (board[i][column] == value)
        {
            return false;
        }
    }
    // 3*3 박스 검사
    int startRow = (row / 3) * 3;
    int startCol = (column / 3) * 3;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[startRow + i][startCol + j] == value)
            {
                return false;
            }
        }
    }

    return true;
}

void BackTrack(int index)
{
    if (index == check.size())
    {
        // 출력부
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                cout << board[i][j] << ' ';
            }   
            cout << '\n';
        }   
        exit(0);
    }

    int row = check[index].first;
    int col = check[index].second;

    for (int i = 1; i <= 9; ++i)
    {
        if (IsValid(row, col, i))
        {
            board[row][col] = i;
            BackTrack(index + 1);
            board[row][col] = 0; // 복구
        }
    }
}