/**
* 백준 ﻿A+B - 3_10950
* 입력받은 두 정수의 합을 출력한다.
* 
* 제한사항
*****************************************
* Test == t;							*
* 0 < A, B < 10							*
*****************************************
*
*
*
* 주의
*
* 풀이시간 1분
*/
#include <iostream>

using namespace std;

int main()
{
    int t, A, B;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> A >> B;
        cout << A + B << endl;
    }

    return 0;
}