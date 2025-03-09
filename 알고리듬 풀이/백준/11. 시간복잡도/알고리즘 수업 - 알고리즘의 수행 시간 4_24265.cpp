/**
 * 백준 알고리즘 수업 - 알고리즘의 수행 시간 4_24265
 * 반복문 중첩을 통해 모든 항을 곱한뒤 더하는 프로그램
 * 수식은 an ** 2 + bn + c이므로 최고차항의 계수는 2, 수행 시간은 n**2만큼 반복한다.
 * MenOfPassion(A[], n) {
 *     sum <- 0;
 *     for i <- 1 to n - 1
 *         for j <- i + 1 to n
 *             sum <- sum + A[i] × A[j]; # 코드1
 *     return sum;
 * }
 * 
 * 
 * 제한사항
 *****************************************
 * 0 < n <= 500,000                      *
 *****************************************
 *
 *
 *
 * 주의
 * 반복문의 식을 잘 확인하자
 * 최고 입력 횟수가 50만번 이므로 최대 연산 횟수는 20억번이 넘어가기 때문에 자료형이 바뀌어야 한다.
 * 
 * 풀이시간 0분
 */


#include <iostream>

using namespace std;

int main(void)
{
    long long int n, sum = 0;
    cin >> n;

    
    for (int i = 0; i < n-1; ++i)
    {
        for (int j = i+1; j < n; ++j)
        {
            sum ++;
        }
    }
    cout << sum << '\n' << 2 << endl;
    return 0;
}