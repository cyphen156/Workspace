/**
* 백준 2908 상수
* 두 수를 입력받고 입력받은 자릿수를 역순으로 바꾼 후 비교하여 큰 수를 출력하면 된다.
* 이 문제의 핵심은 입력 데이터의 강제 형변환 또는 자릿수 파싱, 그리고 비교 연산이다.
* 
* 
* 제한사항
*****************************************
* 0 < Input < 1,000                     *
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
#include <algorithm>

using namespace std;

int main()
{
    string first, second;

    cin >> first >> second;

    reverse(first.begin(), first.end());
    reverse(second.begin(), second.end());

    if (stoi(first) > stoi(second))
    {
        cout << first << '\n';
    }
    else 
    {
        cout << second << '\n';
    }
    return 0;
}
