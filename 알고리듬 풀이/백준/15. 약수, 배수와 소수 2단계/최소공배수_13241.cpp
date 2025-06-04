/**
 * 백준 최소공배수_13241
 * 두 수가 주어졌을 때 최소공배수를 작성하는 프로그램을 만드는데 
 * 입력 데이터가 매우 크다.
 * 
 * 제한사항
 **************************************************
 * 입력의 반은 1,000보다 작다.                      *
 * 나머지 반은 1,000보다 크고, 100,000,000보다 작다. *
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

long long int GCD(long long int A, long long int B);
long long int LCM(long long int A, long long int B, long long int GCD);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    long long int A, B;
    cin >> A >> B;
    cout << LCM(A, B, GCD(A, B)) << '\n';

    return 0;
}


long long int GCD(long long int A, long long int B)
{
    int temp;
    while(B != 0)
    {
        temp = A % B;
        A = B;
        B = temp;
    }
    return A;
}

long long int LCM(long long int A, long long int B, long long int GCD)
{
    return (A * B) / GCD;
}