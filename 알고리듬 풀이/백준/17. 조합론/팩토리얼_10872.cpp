/**
 * 백준 팩토리얼_10872
 * 팩토리얼 연산기
 * 
 * 제한사항
 *****************************************
 * 0 <= N <= 12                          *
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    int result = 1;

    for (int i = 1; i < N + 1; ++i)
    {
        result *= i;
    }

    cout << result << '\n';
    return 0;
}