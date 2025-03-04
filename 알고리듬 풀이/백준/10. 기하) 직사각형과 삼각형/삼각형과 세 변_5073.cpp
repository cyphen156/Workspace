/**
 * 백준 삼각형과 세 변_5073
 * 입력에 따른 출력문 제어2
 * 이번엔 각도가 아닌 변의 길이가 주어진다.
 * 출력예시
 * 세 변의 길이가 모두 같은 경우            :   Equilateral
 * 두 변의 길이만 같은 경우                 :   Isosceles
 * 세 변의 길이가 모두 다른 경우            :   Scalene
 * 삼각형의 조건을 만족하지 못하는 경우에는  :   Invalid
 * 
 * 제한사항
 *****************************************
 * 0 < Line < 1,000                      *
 * if line inputs 0, 0, 0 :: Exit();     *
 *****************************************
 *
 *
 *
 * 주의
 * 삼각형이 성립하는 조건을 주의하자.
 * 두 변의 합이 가장 긴 변보다 커야 한다. 
 * 
 * 풀이시간 10분
 */


#include <iostream>

using namespace std;

int main(void)
{
    while (true)
    {
        int first, second, third;
        cin >> first >> second >> third;

        // Exit() 시퀀스
        if (first == 0 && second == 0 && third == 0)
        {
            break;
        }

        // 가장 긴 변 먼저 찾아야 된다. 
        int hypotenuse = first;
    
        if (hypotenuse < second)
        {
            hypotenuse = second;
        }
            
        if (hypotenuse < third)
        {
            hypotenuse = third;
        }
        
        // 삼각형의 성립조건 :: 가장 긴 변 < 나머지 두 변의 합
        // ==> 가장 긴 변 < 세 변의 합 - 가장 긴 변
        // ==> 2 * 가장 긴 변 < 세 변의 합
        if ((2 * hypotenuse >= (first + second + third)) || first == 0 || second == 0 || third == 0)
        {
            cout << "Invalid" << endl;
            continue;
        }
        
        if (first == second || second == third || first == third)
        // 두 변의 길이가 같은 경우
        {
            if ((first == second) && (first == third))
            // 세 변의 길이가 모두 같은 경우
            {
                cout << "Equilateral" << endl;
            }
            else 
            {
                cout << "Isosceles" << endl;
            }
        }
        else 
        // default 세 변의 길이가 모두 다른 경우
        {
            cout << "Scalene" << endl;
        }
    }
    return 0;
}