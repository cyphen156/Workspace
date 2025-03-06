/**
 * 백준 알고리즘 수업 - 알고리즘의 수행 시간 3_24264
 * 반복문 중첩을 통해 모든 항을 곱한뒤 더하는 프로그램
 * 수식은 an ** 2 + bn + c이므로 최고차항의 계수는 2, 수행 시간은 n**2만큼 반복한다.
 * MenOfPassion(A[], n) {
 *     sum <- 0;
 *     for i <- 1 to n
 *         for j <- 1 to n
 *             sum <- sum + A[i] × A[j]; # 코드1
 *     return sum;
 * }
 * 
 * 제한사항
 *****************************************
 * 
 *****************************************
 *
 *
 *
 * 주의
 * 
 * 
 * 풀이시간 1분
 */


#include <iostream>

using namespace std;

int main(void)
{
    long long int n;
    cin >> n;
    cout << n * n << '\n' << 2 << endl;
    return 0;
}