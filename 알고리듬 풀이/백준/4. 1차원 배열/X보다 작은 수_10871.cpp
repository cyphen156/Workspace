/**
* 백준 1차원 배열 10871
* 정수 N개로 이루어진 수열 A와 X를 주었을 때 X보다 작은 수를 모두 출력하라.
* new delete 연산을 통한 동적 할당 연습 
*
* 제한사항
*****************************************
* 0 < N, X <= 10,000                   *
* 0 < result <= N                       *
*****************************************
*
*
*
* 주의
* 수를 입력받은 순서대로 공백을 주어 출력한다
* --> 정렬 안한다.
* ----> 브루트 포스식으로 전체를 순회해야한다.
*
* 풀이시간 10분
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N, X;
    cin >> N >> X;

    int* arr = new int[N];
    vector<int> result;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
        if (arr[i] < X)
        {
            result.push_back(arr[i]);
        }
    }
    for(int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    delete[] arr;
    return 0;
}