/**
 * 백준 블랙잭_2798
 * 변형 블랙잭
 * 주어진 N장의 카드 중 3장을 골라 M이하의 가장 큰 수를 만들어야 한다.
 * 
 * 제한사항
 *****************************************
 * 2 < N <= 100                          *
 * 9 < M <= 300,000                      *
 * 0 < InputCase <= 100,000              *
 * A + B + C <= M                        *
 *****************************************
 *
 *
 *
 * 주의
 * 카드는 무조건 3장 쓴다.
 * 브루트 포스는 끝까지 다 탐색해봐야 한다. 
 * 
 * 풀이시간 20분
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int a, b, c, N, M;
    cin >> N >> M;

    int sum = 0;
    int temp = sum;
    vector<int> arr;

    for (int i = 0; i < N; ++i)
    {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    for (int i = 0; i < N-2; ++i)
    {
        for (int j = i+1; j < N-1; ++j)
        {
            for (int k = j + 1; k < N; ++k)
            {
                temp = arr[i] + arr[j] + arr[k];
                if (temp > sum && temp <= M)
                {
                    sum = temp;
                }
            }
        }
    } 
    cout << sum;
    return 0;
}