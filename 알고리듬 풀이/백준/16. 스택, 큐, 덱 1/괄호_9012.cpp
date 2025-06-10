/**
 * 백준 괄호_9012
 * 올바르지 않은 괄호 쌍이 존재하는지 아닌지를 판단해서 YES와 NO로 출력하라.
 * 
 * 제한사항
 *****************************************
 * Correct : (())                        *
 * InCorrect : )(()(), (()               *
 *****************************************
 *
 *
 *
 * 주의
 * 저처럼 stdio 헤더랑 iostream 같이 쓰면 오답처리되니 하지마세요 * 
 * 
 * 풀이시간 5분
 */


#include <iostream>
#include <stdio.h>

using namespace std;

int main(void)
{
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        char str[51];
        scanf("%s", str);
        
        int j = 0;
        int size = 0;
        bool isVPS = true;

        while(str[j] != '\0')
        {
            if (str[j] == '(')
            {
                size++;
            }
            else if(str[j] == ')')
            {
                size--;
                
                if (size < 0)
                {
                    isVPS = false;
                    break;
                }
            }
            j++;
        }

        if (size != 0)
        {
            isVPS = false;
        }

        if (isVPS)
        {
            cout << "YES" << '\n';
        }
        else 
        {
            cout << "NO" << '\n';
        }
    }
    return 0;
}