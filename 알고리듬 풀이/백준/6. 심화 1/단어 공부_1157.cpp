/**
 * 백준 단어 공부_1157
 * 대소문자 구분 없이 알파벳 갯수를 세어 가장 많이 나온 철자를 리턴하면 되는 프로그램.
 * 
 * 제한사항
 *****************************************
 * 0 <= strlen <= 1,000,000              *
 * if most Used Alpha Case is not only One
 * return '?'                            *
 *****************************************
 *
 *
 *
 * 주의
 * 
 * 
 * 풀이시간 60분
 */


#include <iostream>
#include <cctype>

using namespace std;

int main(void)
{
    int alpha[26] = { 0 }; // char cnt
    int mostManyUsed = -1; // char index
    bool isMultiple = false;
    string str;
    cin >> str;

    // 문자열 빈도 누계
    for (int i = 0; i < str.length(); ++i)
    {
        int idx = toupper(str[i])-'A';
        alpha[idx]++;
    }

// 0번 인덱스가 문제가 되는디...
    for (int i = 0; i < 26; ++i)
    {
        if (alpha[i] > alpha[mostManyUsed] || i == 0)
        {
            mostManyUsed = i;
            isMultiple = false;
        }
        else if (alpha[i] == alpha[mostManyUsed])
        {
            isMultiple = true;
        }
    }

    if (isMultiple)
    {
        cout << '?' << endl;
    }
    else
    {
        cout << char(mostManyUsed + 'A') << endl;
    }
    return 0;
}