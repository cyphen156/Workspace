/**
 * 백준 세탁소 사장 동혁_2720
 * 거스름 돈 계산기
 * 
 * 제한사항
 *******************************************
 * Test T                                  *
 * 0 < Max Val <= 5.00$ ==> 0 < Cent <= 500*
 * Quarter : 0.25$                         *
 * Dime : 0.1$                             *
 * Nickel : 0.05                           *
 * Penny : 0.01$                           *
 * 받는 동전의 개수를 최소로                 *
 *******************************************
 *
 *
 *
 * 주의
 * 테스트 케이스 조건에 의해 거스름 돈이 0인 경우는 없다.
 * 
 * 풀이시간 20분
 */

#include <iostream>

using namespace std;

int main(void)
{
    // T = TestCastCnt
    int T = 0;
    int divideValues[4] = { 25, 10, 5, 1 };
  

    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        int inputValue;
        cin >> inputValue;
        int rtnValues[4] = { 0 };

        for (int j = 0; j < size(divideValues); ++j)
        {
            int temp = inputValue / divideValues[j];
            inputValue %= divideValues[j];
            rtnValues[j] = temp;
            cout << rtnValues[j] << " ";
        }    

        cout << endl;
    }

    
    return 0;
}