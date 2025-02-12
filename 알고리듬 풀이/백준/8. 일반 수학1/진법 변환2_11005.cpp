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
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    int inputNumber = 0, PositionalNumberSystem;
    string changedNumber = "";
    
    cin >> inputNumber >> PositionalNumberSystem;
    while (inputNumber > 0)
    {
        // 나머지 먼저 찾고
        int temp = (inputNumber % PositionalNumberSystem);
        // 몫
        inputNumber /= PositionalNumberSystem;
        
        if (temp >= 10)
        {
            // temp가 10보다 크면 10이상의 진수라는것을 의미하니 아스키값 보정이 필요함
            // '9' = 48 + 9, 'A' = 65(48+9+)
            temp += 7; 
        }    
        changedNumber += ('0' + temp);
    }
    reverse(changedNumber.begin(), changedNumber.end());
    cout << changedNumber;
    return 0;
}