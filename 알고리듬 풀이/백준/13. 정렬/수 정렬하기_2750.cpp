/**
 * 백준 수 정렬하기_2750
 * 오름차순 정렬해라 애송이
 * // 기본 정렬 버블 정렬
 * 
 * 제한사항
 *****************************************
 * 0 < N <= 1,000                        *
 * -1,000 <= Input <= 1,000              *
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
    int N;
    cin >> N;
    
    int* arr = new int[N]; 
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < N-1; ++i)
    {
        for (int j = i+1; j < N; ++j)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        cout << arr[i] << '\n';
    }
    return 0;
}