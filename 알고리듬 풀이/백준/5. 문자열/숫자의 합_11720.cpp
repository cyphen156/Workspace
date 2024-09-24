/**
* 백준 11720 숫자의 합
* N개의 숫자가 공백없이 입력될 때 이 숫자를 모두 합해서 출력하는 프로그램
* 문자열로 입력받아 1개씩 쪼개 데이터를 저장하기
* 
* 
* 제한사항
*****************************************
* 0 < N <= 100                          *
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
    int T, sum = 0;

    cin >> T;

    string str;
    cin >> str;

    for (char ch:str)
    {
        sum += ch - 48;
    }

    cout << sum << '\n';
    return 0;
}
