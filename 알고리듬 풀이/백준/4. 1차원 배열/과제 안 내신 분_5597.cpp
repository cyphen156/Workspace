/**
* 백준 1차원 배열 10813 공 바꾸기
* 한정된 숫자 내에서 빠진 숫자를 찾는 프로그램
*
* 제한사항
*****************************************
* 0 < N <= 30                           *
* nInput == 28                          *
*****************************************
*
*
*
* 주의
* 출력시 오름차순 정렬 출력
* 
*
* 풀이시간 5분
*/

#include <iostream>

using namespace std;

int main() 
{
    int N, cnt = 0;
    int* arr = new int[31]{ 0 };

    for (int i = 0; i < 28; ++i)
    {
        cin >> N;
        arr[N] = 1;
    }

    for (int i = 1; i < 31; ++i)
    {
        if (arr[i] == 0)
        {
            cout << i << "\n";
            ++cnt;
        }
        if (cnt == 2)
            break;
    }
    delete[] arr;
    return 0;
}