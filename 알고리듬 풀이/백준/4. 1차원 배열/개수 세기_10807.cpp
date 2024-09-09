/**
* 백준 1차원 배열 10807 개수 세기
* N개의 정수중 정수 V의 개수 세기
* 
* 제한사항
*****************************************
* 0 < N <= 100							*
* -100 <= V <= 100                      *
*****************************************
*
*
*
* 주의
* INPUT의 범위가 명시되어 있지 않지만 V값으로 추론이 가능하다. 
*
* 풀이시간 5분
*/
#include <iostream>

using namespace std;

int main(void)
{
    int N, V, result = 0;
    cin >> N;

    int* arr = (int*)malloc(N * sizeof(int));

    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }    
    cin >> V;
    for (int i = 0; i < N; ++i)
    {
        if (arr[i] == V)
        {
            ++result;
        }
    }    
    cout << result << endl;
    free(arr);
	return 0;
}