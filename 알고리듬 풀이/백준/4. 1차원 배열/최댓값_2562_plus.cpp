/**
* 백준 1차원 배열 2562 최댓값
* 9개의 서로 다른 자연수가 주어질 때 최댓값을 찾고 몇번째 수인지 구하는 프로그램을 작성하시오.
* 입력과 동시에 MAX값 비교, 순서 저장
*
* 제한사항
*****************************************
* 0 < INPUT < 100                       *
*****************************************
*
*
*
* 주의
* 첫째 줄에 최댓값을 출력하고, 둘째 줄에 몇번째 수인지 출력한다.
*
* 풀이시간 5분
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int INPUT, MAX = 0;
    vector<int> position;

    for (int i = 0; i < 9; ++i)
    {
        cin >> INPUT;
        if (INPUT > MAX)
        {
            MAX = INPUT;
            position.clear();
            position.push_back(i + 1);    
        }
        else if (INPUT == MAX)
        {
            position.push_back(i + 1);  // 중복된 최댓값의 위치 저장
        }
    }

    cout << MAX << "\n";
    for (int pos : position)
    { 
        cout << pos << " ";
    }
    cout << endl;
    return 0;
}