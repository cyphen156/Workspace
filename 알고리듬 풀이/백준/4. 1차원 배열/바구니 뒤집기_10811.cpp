/**
* 백준 1차원 배열 10811 바구니 뒤집기
* N개의 바구니가 오름차순으로 정렬되어 있는데, (i ~ j)번 바구니를 M회 입력받아 순서를 역순으로 바꾼다. 
* 출력은 왼쪽부터 순서대로 출력한다.
*
* 제한사항
*****************************************
* 0 < N, M <= 100                       *
* 0 < i <= j <= N                       *
*****************************************
*
*
*
* 주의
* 
*
* 풀이시간 5분
*/

#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int N, M, i, j;
    cin >> N >> M;

    vector<int> arr;

    for (int t = 0; t < N+1; ++t)
    {
        arr.push_back(t);
    }

    for (int t = 0; t < M; ++t)
    {
        cin >> i >> j;
        for (int IDX = i; i < j; ++i, --j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    for (int t = 1; t < N+1; ++t)
    {
        cout << arr[t] << " ";
    }
    return 0;
}