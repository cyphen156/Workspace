/**
 * 백준 파도반 수열_9461
 * 위와 같은 그림으로 배치되는 정 삼각형이 존재한다.
 * 정삼각형의 개수 N이 주어질 때 마지막 정삼각형의 변의 길이 P(N)를 구하라
 * N = (N-1) + (N - 5)
 * if (N == 1 || N == 2 || N == 3)
 *  return 1;
 * 
 * if  (N == 4)
 * N = N-1 + N-3
 * 
 * if (N == 5)
 * N = N-1
 * 
 * 제한사항
 *****************************************
 * Test T                                *
 * 0 < N <= 100                          *
 *****************************************
 *
 *
 *
 * 주의
 * 결과 반환 값이 int 인덱스를 넘어갈 수 있다. long long int  쓰자
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 5 + 25분
 */


#include <iostream>

#define MAX_SIZE 101

static int N;

static long long int memoizationArray[MAX_SIZE] = { 0 };

long long int DynamicProgramming(int length);

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        cin >> N;
        cout << DynamicProgramming(N) << '\n';
    }

    return 0;
}

long long int DynamicProgramming(int length)
{
    if (memoizationArray[length] != 0)
    {
        return memoizationArray[length];
    }

    if (length == 1)
    {
        return memoizationArray[length] = 1;
    }

    if (length == 2 || length == 3)
    {
        return memoizationArray[length] = DynamicProgramming(length - 1);
    }
 
    if (length == 4)
    {
        return memoizationArray[length] = DynamicProgramming(length - 1) + DynamicProgramming(length - 3);
    }

    if (length == 5)
    {
        return memoizationArray[length] = DynamicProgramming(length - 1);
    }

    else
    {
        return memoizationArray[length] = DynamicProgramming(length - 1) + DynamicProgramming(length - 5);
    }
}