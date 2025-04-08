/**
 * 백준 체스판 다시 칠하기_1018
 * M * N크기의 보드를 8 * 8 크기로 다시 구성하는데, 흰색과 검정색이 번갈아가며 색칠된다. 
 * 맨 처음 초기 색이 지정되어 보드가 제공된다고 했을 때 가장 적은 색 교체로 체스판을 다시 만들 수 있을지 알아내라
 * 
 * 제한사항
 *****************************************
 * 8 <= N, M <= 50                       *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 60분
 */


#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    // 선언
    int col, row;
    cin >> row >> col;

    char** board = new char*[row];
    for (int i = 0; i < row; ++i)
    {
        board[i] = new char[col];
    }
    
    // 입력
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            cin >> board[i][j];
        }
    }

    int result = 64; // 맥스
    
    // 재배열
    for (int i = 0; i <= row-8; ++i)
    {
        for (int j = 0; j <= col-8; ++j)
        {
            int changedColor = 0;
            char start = board[i][j];   // 시작 인덱스 저장
            
            for (int k = 0; k < 64; ++k)
            {
                int t = k / 8;
                int s = k % 8;
                char current = board[i + t][j + s];

                if ((t + s) % 2 == 0)   // 짝수 위치: 시작 색과 같아야 함
                {
                    if (current != start)
                        changedColor++;
                }
                else  // 홀수 위치: 시작 색과 반대여야 함
                {
                    if (current == start)
                        changedColor++;
                }
            }

            // 반전 색 패턴과도 비교
            changedColor = min(changedColor, 64 - changedColor);
            result = min(result, changedColor);
        }
    }
    // 결과 출력
    cout << result;

    // 해제
    for (int i = 0; i < row; ++i)
    {
        delete[] board[i];
    }
    delete[] board;

    return 0;
}