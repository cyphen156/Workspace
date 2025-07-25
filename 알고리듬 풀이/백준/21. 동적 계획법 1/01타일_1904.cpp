/**
 * 백준 01타일_1904
 * 1 또는 00 두가지 케이스가 존재한다.
 * 이 두가지 케이스를 통해 N이 주어졌을 때 만들 수 있는 모든 수열의 가짓수를 구하라.
 * ex)
 * N == 1 : (1 / 0)
 * N == 2 : (11, 00, / 10, 01)
 * N == 3 : (111, 100, 001 / 110, 101, 010, 011, 000)
 * N == 4 : (1111, 1100, 1001, 0011, 0000 / ...)
 * 
 * 결과 출력시 길이가 N인 모든 2진 수열의 개수를 15746으로 나눈 나머지를 출력한다.
 * 
 * 점화식은 n = n-1 + n-2
 * if (n == 1 : 1)
 * if (n == 2 : 2)
 * 
 * 제한사항
 *****************************************
 * 0 < N <= 1,000,000                    *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 5 + 20분
 */


#include <iostream>

#define MAX_SIZE 1000001
#define MOD 15746

using namespace std;

static int N;   // length

static int memoizationArray[MAX_SIZE] = { 0 };

int DynamicProgramming(int setp);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;


    cout << DynamicProgramming(N) << '\n';
    return 0;
}

int DynamicProgramming(int length)
{
    // if (length == 1) 
    // {
    //     memoizationArray[length] = 1;
    // }

    // if (length == 2)
    // {
    //     memoizationArray[length] = 2;
    // }

    memoizationArray[1] = 1;
    memoizationArray[2] = 2;
    
    if (memoizationArray[length] != 0)
    {
        return memoizationArray[length];
    }

    // return memoizationArray[length]
    //  = (DynamicProgramming(length - 1)
    //   + DynamicProgramming(length - 2)) % MOD;

    for(int i=3; i <= N; i++){
        memoizationArray[i] = (memoizationArray[i-1] + memoizationArray[i-2]) % MOD;
    }
    
    return memoizationArray[N];
}