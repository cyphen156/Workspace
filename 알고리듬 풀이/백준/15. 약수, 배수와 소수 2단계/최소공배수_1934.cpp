/**
 * 백준 최소공배수_1934
 * 최소공배수를 구하는데 유클리드 호제법을 사용해서 구해라
 * 
 * 제한사항
 *****************************************
 * 0 < Test T < 1,000                    *
 * 0 < A, B <= 45,000                    *
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

int GCD(int A, int B);
int LCM(int A, int B, int GCD);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int A, B;
        cin >> A >> B;
        cout << LCM(A, B, GCD(A, B)) << '\n';
    }

    return 0;
}

int GCD(int A, int B)
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

int LCM(int A, int B, int GCD)
{
    return (A * B) / GCD;
}