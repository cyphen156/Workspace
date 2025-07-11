/**
 * 백준 이항 계수 1_11050
 * 이항 계수는 두개의 항을 전개 했을 때 나타나는 각 항의 계수를 말한다.
 * (Ex : (X + Y)^2 = X^2 + 2XY + Y^2
 * 수식은 다음과 같다.
 * 
 * 제한사항
 *****************************************
 * 0 < K <= N <= 10                      *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 10분
 */


#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    int N, K;
    cin >> N >> K;

    // N! / (N-K)!
    int numerator = 1;
    for (int i = N; i > N-K; --i)
    {
        numerator *= i;    
    }

    // K!
    int denominator = 1;
    for (int i = 1; i <= K; ++i)
    {
        denominator *= i;
    }

    int result = numerator / denominator;

    cout <<  result << '\n';

    return 0;
}