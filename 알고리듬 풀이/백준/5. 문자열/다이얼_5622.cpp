/**
* 백준 다이얼_5622
* 위 그림과 같은 다이얼 전화기가 있다. 전화를 걸려면 해당 숫자가 맨 오른쪽 하단에 위치해야 한다.
* 한 칸을 이동하는데 걸리는 시간은 1초가 걸린다 숫자 1-> 2초, 숫자 0 -> 11초
* 알파벳입력을 숫자로 대체해야 한다.
* 
* 제한사항
*****************************************
* str is always upperCase               *
* 1 < strLength <= 15                   *
*****************************************
*
*
*
* 주의
* 그림을 주의해서 보자
* 1과 0은 문자에 대응하지 않음
* 26개문자를 8개의 숫자로 처리해야함
* 문자 갯수가 일정하지 않음
* ABC / DEF / GHI / JKL / MNO / PQRS / TUV / WXYZ
*
* 풀이시간 30분
*/


#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string str;
    int result = 0;

    cin >> str;

    for (char ch:str)
    {
        int temp = ((ch - 'A') / 3) + 3;

         if (ch == 'S' || ch == 'V' || ch == 'Y' || ch == 'Z')
        {
            --temp;
        }

        result += temp;
    }

    cout << result << '\n';
    return 0;
}