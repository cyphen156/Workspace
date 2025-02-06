/**
 * 백준 진법 변환_2745
 * N진의 수가 입력되면 10진법으로 변환하여 출력하는 프로그램
 * 첫번째 입력으로는 수가 
 * 문자열 파싱할 줄 알면 쉽다.
 * 
 * 제한사항
 *********************************************
 * 2 <= N <= 36                              *
 * -1,000,000,000 <= Result <= 1,000,000,000 *
 *********************************************
 *
 *
 *
 * 주의
 * 최댓값이 큰 숫자이다. 하지만 32비트 자료형으로 충분하다.
 * 
 * 풀이시간 50분
 */


#include <iostream>

using namespace std;

int main(void)
{
    string inputNumber;
    int PositionalNumberSystem, changedNumber = 0;
    cin >> inputNumber >> PositionalNumberSystem;

    for (int i = 0; i < inputNumber.length(); ++i)
    {
        // 일단 문자를 숫자로 변환하기
        // --> AToI
        // 일단 ASCII 48만큼 빼면 숫자에 대한 처리 완료 
        // 0 ~ 9
        int temp = inputNumber[i] - 48;

        // 변환 값이 9보다 크면 진법수라는 것을 의미한다.
        // -> :, ;, <, =, >, ?, @ 라는 아스키 값은 제외
        // A ~ Z
        if (temp > 9)
        {
            temp -= 7;
        }

        // 변환 완료된 숫자를 더해라
        changedNumber = changedNumber * PositionalNumberSystem + temp;        
        }

    cout << changedNumber << endl;
    return 0;
}