/**
 * 백준 분수합_1735
 * 숫자가 두 개씩 두 번 주어진다.
 * 두 수 중 첫번째 수는 분자, 두번째 수는 분모를 구성한다.
 * 두 분수가 구성되었을 때 둘을 합하여 기약분수의 형태로 구하는 프로그램을 작성하시오.
 * 
 * 제한사항
 *****************************************
 * 0 < Input <= 30,000                   *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 20분
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
    int numerA, numerB;
    int denomA, denomB;

    cin >> numerA >> denomA;
    cin >> numerB >> denomB;

    // 공통 분모 만들기
    int gcd = GCD(denomA, denomB);
    int lcm = LCM(denomA, denomB, gcd);

    // 공통 분모에 맞춘 분자 계산
    int resultNumer = numerA * (lcm / denomA) + numerB * (lcm / denomB);
    int resultDenom = lcm;

    // 결과 약분
    int finalGCD = GCD(resultNumer, resultDenom);
    resultNumer /= finalGCD;
    resultDenom /= finalGCD;

    cout << resultNumer << " " << resultDenom << '\n';

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