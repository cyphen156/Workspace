/**
 * 백준 그룹 단어 체커_1316
 * 각 문자가 연속해서 나타나는 경우를 체크해야 한다.
 * Ex) abbbcdde -> 그룹단어 a, bbb, c, dd, e
 * 다음의 경우는 단어 중 일부가 연속되는 패턴이 깨졋기 때문에 그룹단어가 아니다.
 * Ex) aabbbcbdde -> 그룹단어 aa, c, dd, e / 그룹단어가 아닌 단어 bbb" "b
 * 
 * 제한사항
 ************************************************
 * all Case Must Be Close Together              *
 * first Input value(N) Means Number of Word    *
 * 0 < N <= 100                                 *
 * each Word consist of lowerCase               *
 * 0 < Word <= 100                              *
 ************************************************
 *
 *
 *
 * 주의
 * 
 * 
 * 풀이시간 40분
 */


#include <iostream>

using namespace std;

int main(void)
{
    int numberOfCase, cnt = 0;
    cin >> numberOfCase;
    
    for (int i = 0; i < numberOfCase; ++i)
    {
        string str;
        cin >> str;
        bool isGroupWord = true;
        bool alpha[26] = { 0 };
        for (int j = 0; j < str.length(); ++j)
        {
            int index = str[j]-'a'; // 알파벳 위치 인덱싱
            if (str[j] != str[j+1]) 
            // 현재 단어랑 다음 단어가 다른 단어임 = 알파벳이 바뀌어 새로운 그룹단어를 형성함을 의미
            {   
                if (alpha[index])
                // 이미 한번 등장했던 그룹단어임 == 새로 등장할 때는 그룹단어가 아님을 의미
                {
                    isGroupWord = false;
                    break;
                }
                alpha[index] = true;
            }
            
        }
        if (isGroupWord)
        {
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}