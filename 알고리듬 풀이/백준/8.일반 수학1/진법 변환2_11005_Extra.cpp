/**
 * 백준 진법 변환2_11005
 * 진법변환1의 역방향
 * 10진법 수를 N진법으로 변환하여 출력하는 프로그램
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
 * Z는 36진법수이기 때문에 표현 범위가 35까지이다.
 * --> 36은 자릿수올림
 * 
 * 풀이시간 0분
 */


#include <iostream>

using namespace std;

int main(void)
{
    int inputNumber = 0;
    char PositionalNumberSystem;
    int changedPositionalNumberSystem = 0;
    int MaxPosition = 1;
    cin >> inputNumber >> PositionalNumberSystem;

    changedPositionalNumberSystem = PositionalNumberSystem - '0';
    if (changedPositionalNumberSystem > 9)
    {
        // 1차 변환시 9보다 큰 값이 튀어나오면 변환시킬 진법수가 10진수 이상이라는 것을 의미한다.
        // 아스키값 보정
        changedPositionalNumberSystem - 
    }
    // 0 ~ 9 문제 없음


    return 0;
}