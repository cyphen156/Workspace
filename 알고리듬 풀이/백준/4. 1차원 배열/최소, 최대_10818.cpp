/**
* 백준 1차원 배열 10818 최소, 최대
* 입력된 정수들의 최소, 최대값을 구하는 프로그램
* 두가지 방법이 존재한다.
* 모든 정수를 입력받은 이후 최소, 최대값을 연산할 것인지?->C풀이
* 입력받는 즉시 최소, 최대값을 비교하여 순회 횟수를 줄일 것인지?-> C++풀이
* <limits> 또는 <climits> 둘 중하나를 사용
*
* 제한사항
*****************************************
* 0 < N <= 1,000,000                    *
* -1,000,000 <= INPUT <= 1,000,000      *
*****************************************
*
*
*
* 주의
* 첫째 줄에 주어진 정수 N개의 최솟값과 최댓값을 공백으로 구분해 출력한다.
* 
* 풀이시간 5분
*/
#include <iostream>
#include <limits> // std::numeric_limits<자료형>::min/max();
#include <climits> // INT_MIN, INT_MAX;
#include <vector>

using namespace std;

int main(void)
{
    int N, MIN = INT_MAX;
    int MAX = std::numeric_limits<int>::min();

    cin >> N;
    vector<int> arr;
    for (int i = 0; i < N; ++i)
    {
        int INPUT;
        cin >> INPUT;
        arr.push_back(INPUT);
        if (INPUT <= MIN)
        {
            MIN = INPUT;
        }
        if (INPUT >= MAX)
        {
            MAX = INPUT;
        }
    }

    cout << MIN << " " << MAX << endl;
    return 0;
}