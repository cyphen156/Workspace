/**
* 백준 그대로 출력하기_11718
* 입력받은
* 
* 제한사항
*****************************************
* input case == alpha, blank, intiger   *
* 0 <= input trial <= 100               *
* 0 <= input case len <= 100            *
* input case do not start and end blank *
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

int main(void)
{
    string str;
    while (getline(cin, str))
    {
        cout << str << '\n';
    }

    return 0;
}