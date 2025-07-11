/**
 * 백준 팩토리얼 2_27433
 * 팩토리얼 연산 재귀호출로 구성하기
 * 
 * 제한사항
 *****************************************
 * 0 <= N <= 20                           *
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

long long int recursive(long long int input);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int N;
    cin >> N;

    cout << recursive(N) << '\n';
    return 0;
}

long long int recursive(long long int input)
{
    if (input == 0 || input == 1)
    {
        return 1;
    }
    else 
    {
        input *= recursive(input - 1);
    }

    return input;
}