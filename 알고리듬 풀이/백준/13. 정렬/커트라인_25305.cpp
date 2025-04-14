/**
 * 백준 커트라인_25305
 * 내림차순 정렬해라 애송이
 * // 기본 정렬 버블 정렬
 * 
 * 제한사항
 *****************************************
 * 0 < N <= 1,000                        *
 * 0 < K <= N                            *
 * 0 <= x <= 10,000                      *
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
    int N, K;
    cin >> N >> K;

    int* arr = new int[N]; 
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < N-1; ++i)
    {
        for (int j = i+1; j < N; ++j)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << arr[K-1];
    return 0;
}