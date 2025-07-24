/**
 * 백준 신나는 함수 실행_9184
 * 재귀함수의 유사코드를 주면 그대로 쓰지 말고 시간을 줄여봐라
 * 
 * 
 * 유사코드는 다음과 같다.
 * if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns:
 *     1
 * 
 * if a > 20 or b > 20 or c > 20, then w(a, b, c) returns:
 *     w(20, 20, 20)
 * 
 * if a < b and b < c, then w(a, b, c) returns:
 *     w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
 * 
 * otherwise it returns:
 *     w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
 * 
 * 
 * 제한사항
 *****************************************
 * If InputCase (-1, -1, -1) break;      *
 * -51 < Input <= 50                     *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 1 + 30분
 */


#include <iostream>

#define MAX_VALUE 101

// 범위 축소 알고리즘이 함수 내에 존재함
// -50 ~ 50까지 선언했지만 실제 사용은 0 ~ 20(매핑값 : 50 ~ 70)까지 
static int menoizationArray[MAX_VALUE][MAX_VALUE][MAX_VALUE] = { 0 };   

int RecursiveFunction(int input1, int input2, int input3);

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(1)
    {
        int input1, input2, input3;

        cin >> input1 >> input2 >> input3;
        if (input1 == -1 && input2 == -1 && input3 == -1)
        {
            break;
        }

        cout << "w(" << input1 << ", " << input2 << ", " << input3 << ") = " 
            << RecursiveFunction(input1, input2, input3) << '\n';
    }

    return 0;
}

int RecursiveFunction(int input1, int input2, int input3)
{
    if (input1 <= 0 || input2 <= 0 || input3 <= 0)
    {
        return 1;
    }

    if (input1 > 20 || input2 > 20 || input3 > 20)
    {
        return RecursiveFunction(20, 20, 20);
    }

    int offset = 50;

    int i = input1 + offset;
    int j = input2 + offset;
    int k = input3 + offset;

    if (menoizationArray[i][j][k] != 0)
    {
        return menoizationArray[i][j][k];
    }    
    
    if (input1 < input2 && input2 < input3)
    {
        menoizationArray[i][j][k] = RecursiveFunction(input1, input2, input3 - 1)
             + RecursiveFunction(input1, input2 - 1, input3 - 1)
             - RecursiveFunction(input1, input2 - 1, input3);
    }

    menoizationArray[i][j][k] = RecursiveFunction(input1 - 1, input2, input3)
        + RecursiveFunction(input1 - 1, input2 - 1, input3)
        + RecursiveFunction(input1 - 1, input2, input3 - 1)
        - RecursiveFunction(input1 - 1, input2 - 1, input3 - 1);

    return menoizationArray[i][j][k];
}