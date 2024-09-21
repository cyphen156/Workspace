/**
* 백준 9086 문자열
* 입력받은 문자열의 첫 글자와 마지막 글자를 출력하는 프로그램
* C언어로는 문자열 저장안하고 문자 두개만을 저장할 것이다.
* 
* 
* 제한사항
*****************************************
* 0 < Test T <= 10                      *
* 0 < string <= 1,000                   *
* there is no 'spacing' in "str"        *
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
#include <string>

using namespace std;

int main()
{
    int T;

    cin >> T;

    string* s = new string[3];
    for (int i = 0; i < T; ++i)
    {
        string str;        
        cin >> str;

        s[i] += str.front();
        s[i] += str.back();
    }


    for (int i = 0; i < T; ++i)
    {
        cout << s[i] << '\n';
    }
    delete[] s;

    return 0;
}
