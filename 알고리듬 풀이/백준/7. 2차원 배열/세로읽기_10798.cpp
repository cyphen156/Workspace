/**
 * 백준 세로읽기_10798
 * 문자열을 여러개 입력받아 행단위 읽기에서 열단위 읽기로 출력하는 프로그램
 * 
 * 제한사항
 ************************************************
 * 0 < strLen <= 15                             *
 * inputCase = 5                                *
 * 널문자가 있을 경우 다음 행에 있는 문자를 읽는다. *
 ************************************************
 *
 *
 *
 * 주의
 * 
 * 
 * 풀이시간 0분
 */


#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    // 공백 배열로 초기화
    char strCage[5][15] = {0};

    for (int i = 0; i < 5; ++i)
    {
        string input;
        getline(cin, input);
        for (int j = 0; j < input.length(); ++j)
        {
            strCage[i][j] = input[j];

        }
    }

    // 출력
    for (int i = 0; i < 15; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (strCage[j][i] == '\0')
            {
                continue;
            }
            cout << strCage[j][i];
        }
    }
    return 0;
}