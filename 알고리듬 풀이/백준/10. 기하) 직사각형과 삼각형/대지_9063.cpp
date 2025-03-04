/**
 * 백준 대지_9063
 * 여러개의 좌표를 입력받아 가장 넓은 범위를 갖는 직사각형을 구하는 프로그램
 * 
 * 제한사항
 *****************************************
 * 0 < Inputs <= 100,000                 *
 * -10,000 <= Point <= 10,000            *
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

using namespace std;

int main(void)
{
    int inputs;
    cin >> inputs;

    
    int minX = 10001, minY = 10001, maxX =  - 10001, maxY = - 10001;
    for (int i = 0; i < inputs; ++i)
    {
        int inputX, inputY;
        cin >> inputX >> inputY;
        if (inputs == 1)
        {
            cout << 0 << endl;
            return 0;
        }
        if (inputX < minX)
        {
            minX = inputX;
        }
        if (inputX > maxX)
        {
            maxX = inputX;
        }

        if (inputY < minY)
        {
            minY = inputY;
        }
        if (inputY > maxY)
        {
            maxY = inputY;
        }
    }

    cout << (maxX - minX) * (maxY - minY) << endl; 
    return 0;
}