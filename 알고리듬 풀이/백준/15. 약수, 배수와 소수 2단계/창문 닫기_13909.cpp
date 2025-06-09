/**
 * 백준 창문 닫기_13909
 * 모든 창문을 열었다 닫았다를 진행한 뒤 열려있는 창문의 개수를 구하라.
 * 패턴은 다음과 같다. 
 * 1, 2, 2, 3, 2, 4, 2, 3..
 * 홀수번 뒤집히는 경우는 1과 제곱근을 약수로 갖는 제곱근 수 일 경우 뿐이다. 
 * 
 * 제한사항
 *****************************************
 * 0 < N ≤ 2,100,000,000                 *
 * Memory Capacity <= 64MB               *
 *****************************************
 *
 *
 *
 * 주의
 * 어렵다. 규칙성 찾기 힘들다.
 * 
 * 풀이시간 90분
 */


#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    unsigned long long N;
    cin >> N;
    
    unsigned long long count = sqrt(N);

    cout << count << '\n';
    return 0;
}