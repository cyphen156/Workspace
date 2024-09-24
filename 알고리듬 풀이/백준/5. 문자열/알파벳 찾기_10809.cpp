/**
* 백준 문자열 10809 알파벳 찾기
* 알파벳 표에서 입력받은 문자열에 해당 알파벳이 등장하는 첫 위치를 표시하는 프로그램
* 
* 
* 제한사항
*****************************************
* 0 < S <= 100                          *
* S is Lowercase                        *
* if ch is not in S return -1           *
*****************************************
*
*
*
* 주의
* 없다.
* 
* 풀이시간 5분
*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int* alpha = new int[26];
    memset(alpha, -1, sizeof(int) * 26); 
    string str;

    cin >> str;

    // 범위 기반 루프
    int i = 0;
    for (char ch: str)
    {
        int idx = ch - 'a';
        if (alpha[idx] == -1)
        {
            alpha[idx] = i;
        }
        ++i;
    }

    for (int i = 0; i < 26; ++i)
    {
        cout << alpha[i] << " ";
    }
    delete[] alpha;
    return 0;
}
