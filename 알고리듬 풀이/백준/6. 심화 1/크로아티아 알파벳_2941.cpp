/**
 * 백준 크로아티아 알파벳_2941
 * 
 * č	c=
 * ć	c-
 * dž	dz=
 * đ	d-
 * lj	lj
 * nj	nj
 * š	s=
 * ž	z=
 * 
 * 위의 문자들을 모두 하나의 문자로 생각하여 문자열에서 나타난 단어 개수를 세야 한다.
 * 
 * 제한사항
 ********************************************
 * 0 < strlen <= 100                        *
 * str elements always lower alpha or - or =*
 ********************************************
 *
 *
 *
 * 주의
 * 
 * 
 * 풀이시간 10분
 */


#include <iostream>

using namespace std;

int main(void)
{
    string str;
    cin >> str;

    int cnt = 0;

    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == 'c'|| str[i] == 's' || str[i] == 'z')
        {
            if (str[i] == 'c')
            {
                if (str[i+1] == '-')
                {
                    continue;
                }
            }
            if (str[i+1] == '=')
            {
                continue;
            }
        }
        else if (str[i] == 'd')
        {
            if (str[i+1] == '-')
            {
                continue;
            }
            else if (str[i+1] == 'z' && str[i+2] == '=')
            {
                ++i;
                continue;
            }
        }
        else if (str[i] == 'l' || str[i] == 'n')
        {
            if (str[i+1] == 'j')
            {
                continue;
            }
        }
        ++cnt;
    }

    cout << cnt << endl;
    return 0;
}