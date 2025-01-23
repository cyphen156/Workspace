/**
 * 백준 별 찍기 - 7_2444
 * 
 *     *
 *    ***
 *   *****
 *  *******
 * *********
 *  *******
 *   *****
 *    ***
 *     *
 * 
 * 그려라
 * 
 * 제한사항
 *****************************************
 * 없다.                                 *
 *****************************************
 *
 *
 *
 * 주의
 * 
 * 
 * 풀이시간 10분
 */


#include <iostream>

using namespace std;

int main(void)
{
    int input;
    string str = "";
    cin >> input;
    for (int i = 0; i < input; ++i)
    {
        for (int j = 0; j < input - (i+1); ++j)
        {
            str += " ";   
        }
        for (int j = 0; j < 2*i+1; ++j)
        {
            str += "*";
        }
        str += "\n";
    }
    for (int i = 0; i < input-1; ++i)
    {
        for (int j = 0; j < i+1; ++j)
        {
            str += " ";   
        }
        for (int j = 0; j < 2 * (input-2-i) + 1; ++j)
        {
            str += "*";
        }
        str += "\n";
    }
    cout << str;
    return 0;
}