/**
* 백준 반복문 10951 A + B - 4
*
* 간단하게 반복문을 사용한 덧셈 프로그램
* 
* 제한사항
*****************************************
* (0 < A, B < 10)                       *
*****************************************
*
*
*
* 주의
* EOF가 문제에 명시되있지 않으니 주의해서 푸세요
*
* 풀이시간 1분
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main() {
    int first, second;
    while (1) 
    {
        cin >> first >> second;
        if (cin.eof())
        {
            break;
        }
        cout << first + second << endl;
    }
    return 0;
}
