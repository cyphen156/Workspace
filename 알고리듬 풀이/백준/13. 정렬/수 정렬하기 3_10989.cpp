/**
 * 백준 수 정렬하기 3_10989
 * 중복을 고려한 메모리 절약 정렬 방법 생각해보기
 * Using Counting Sort
 * 
 * 제한사항
 *****************************************
 * 0 < N <= 10,000,000                   *
 * 0 < Input ≤ 10,000                    *
 *****************************************
 *
 *
 *
 * 주의
 * 일반적인 소팅 방법을 사용하면 메모리 인덱스 오류가 발생한다.
 *  입력 갯수는 10,000,000번이니까 메모리가 최소 4 * 10,000,000 Byte가 필요하다
 * ==> 40,000 KB
 * ====> 40 MB
 *  그런데 문제에서 주어진 메모리 양은 8MB
 * 입력 범위가 10,000으로 적은 범위를 갖는다
 * ==> 오름차순 소팅된다고 가정하니까 인덱스에 0이 아니면 출력하면 된다!
 * 
 * 풀이시간 20분
 */


#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; 
    cin >> N;

    int arr[10001] = { 0 };

    for (int i = 0; i < N; ++i)
    {
        int input;
        cin >> input;
        arr[input]++;
    }

    for (int i = 0; i < size(arr); ++i)
    {
        if(arr[i] != 0)
        {
            for (int j = 0; j < arr[i]; ++j)
            {
                cout << i << '\n';
            }
        }
    }
    return 0;
}