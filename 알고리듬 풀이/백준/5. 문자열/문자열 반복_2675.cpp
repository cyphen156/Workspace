/**
* 백준 문자열 2675 문자열 반복
* 문자열 S를 입력받고, 각 문자를 R번 반복해 새로운 문자열을 만들어 출력
* abcde, 3 -> aaabbbcccdddeee
* 
* 
* 제한사항
*****************************************
* 0 < Sentence <= 1,000,000             *
*****************************************
*
*
*
* 주의
* 이스케이프 시퀀스 조심하기
* 
* 풀이시간 10분
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;

    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        int R;
        string str;

        cin >> R >> str;

        for (int j = 0; j < str.length(); ++j)
        {
            for(int k = 0; k < R; ++k)
            {
                cout << str[j];
            }
        }
        cout << '\n';
    }
    return 0;
}
