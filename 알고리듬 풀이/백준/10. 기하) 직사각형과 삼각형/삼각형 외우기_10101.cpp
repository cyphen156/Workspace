/**
 * 백준 삼각형 외우기_10101
 * 입력에 따른 출력문 제어
 * 출력예시
 * 세 각의 크기가 모두 60이면, Equilateral
 * 세 각의 합이 180이고, 두 각이 같은 경우에는 Isosceles
 * 세 각의 합이 180이고, 같은 각이 없는 경우에는 Scalene
 * 세 각의 합이 180이 아닌 경우에는 Error
 * 
 * 제한사항
 *****************************************
 * 0 < degree < 180                      *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 0분
 */


#include <iostream>

using namespace std;

int main(void)
{
    int first, second, third;

    int totalDegree = 0; 

    cin >> first >> second >> third;

    totalDegree = first + second + third;

    if (totalDegree != 180)
    // 삼각형이 아니니?
    {
        cout << "Error" << endl;
    }
    else 
    // 삼각형이긴 한데
    {
        if ((first == second) || (first == third) || (second == third))
        // 두 각이 같니?
        {
            if ((first == 60) || (second == 60) || (third == 60))
            // 두 각이 같은데 한 각이 60도라면 다른 두 각도 필연적으로 60도 == 합은 180 도이기 때문에
            {
                cout << "Equilateral" << endl;
            }
            else
            {
                cout << "Isosceles" << endl;
            }
        }
        else 
        // 세 각이 모두 다르니?
        {
            cout << "Scalene" << endl;
        }
    }
    return 0;
}