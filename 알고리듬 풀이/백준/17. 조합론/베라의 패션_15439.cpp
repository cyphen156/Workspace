/**
 * 백준 베라의 패션_15439
 * 서로 다른 N개의 옷이 존재한다.
 * 상의와 하의로 구분될 때 서로 다른 색상 조합을 구하라
 * 순서가 있는 순열 가짓수 구하기
 * 
 * 제한사항
 *****************************************
 * 0 < N <= 2017                         *
 * N Is Integer                          *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 0분
 */


#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    int N, result;

    cin >> N;

    result = N * (N - 1);
    cout << result << '\n';
    return 0;
}