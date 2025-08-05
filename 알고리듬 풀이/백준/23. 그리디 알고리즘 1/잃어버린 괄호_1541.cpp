/**
 * 백준 잃어버린 괄호_1541
 * unsigned int, +, -, (, )를 통해 수식을 만들고 괄호를 모두 지웠다.
 * 다시 괄호를 구성하여 식의 값을 최소로 만드는 프로그램을 작성하시오.
 * => 연산 우선 순위를 커스터마이징 한다고 보면 된다.
 * +++ 부연 설명
 * 빼는 값이 최대한 커지도록 수식을 구성한다. 
 * => 뺄셈 나오기 전까지 수식을 전부 괄호로 묶어서 최대한 Value를 높인다.
 * 
 * 제한사항
 *************************************************************
 * first Input and End Input Always be Unsigned Intigers     *
 * operator always inputs Alone                              *
 * 0 <= numberValue < 100,000                                *
 * 0 < strlen < 51                                           *
 *************************************************************
 *
 *
 *
 * 주의
 * 뺄셈 연산자가 한번만 나온다는 보장이 없다.
 * Ex) 100 + 10 - 20 - 30 + 40 + 50 - 60
 * = (100 + 10) - (20 + 30) + 40 + 50 - 60
 * = 110 - 50 + 90 - 60
 * = 90
 * ==> (100 + 10) - 20 - (30  + 40 + 50) - 60
 * ==> -90
 * 
 * ==> 뺄셈 연산이 여러번 등장하던 말던 한번 등장했다면 
 * 이후의 모든 연산을 뺄셈 연산으로 처리하는것과 사실상 동일한 로직이다.
 * 풀이시간 (문제 해석 + 구현)
 * 10 + 50분
 */


#include <iostream>
#include <string>

#define MAX_SIZE 51

using namespace std;

static char operators[MAX_SIZE];
static int operands[MAX_SIZE] = { 0 };

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string str;
    cin >> str;

    int operaotorCount = 0, operandCount = 0;
    string integer = "";
    for (char ch : str)
    {
        if (ch >= '0' && ch <= '9')
        {
            integer += ch;
        }
        else
        {
            operands[operandCount++] = stoi(integer);
            integer = "";
            operators[operaotorCount++] = ch;
        }
    }

    if (integer != "")
    {
        operands[operandCount++] = stoi(integer);
        
    }

    int sum = operands[0];  // 첫번째 피연산자 앞은 항상 +연산자가 있다는것을 가정한다. 
    // 9999 + 1 == +9999 + 1
    int temp = 0; 
    int j = 1;
    
    bool isMinus = false;
    
    // 첫번째 풀이
    // for (int i = 0; i < operaotorCount; ++i)
    // {
    //     // 뺄셈 연산이 등장했다.
    //     // => 이전까지 누적된거 총 합에 뺄셈 연산을 적용하고 새 누적을 시작해라. 
    //     if (operators[i] == '-')
    //     {
    //         if (isMinus)
    //         {
    //             sum -= temp;
    //         }
    //         // 뺄셈 연산이 한번도 등장하지 않았을 경우
    //         else
    //         {
    //             sum += temp;
    //         }
    //         isMinus = true;
    //         temp = operands[j];
    //     }        
    //     else 
    //     {
    //         temp += operands[j];
    //     }
    //     ++j;
    // }

    // if (isMinus)
    // {
    //     sum -= temp;
    // }
    // // 뺄셈 연산이 한번도 등장하지 않았을 경우
    // else
    // {
    //     sum += temp;
    // }

    // 두 번째 풀이
    for (int i = 0; i < operaotorCount; ++i)
    {
        // 뺄셈 연산이 등장했다.
        if (operators[i] == '-')
        {
            isMinus = true;
        }
        if (isMinus)
        {
            sum -= operands[j];
        }
        else
        {
            sum += operands[j];
        }
        ++j;
    }

    cout << sum << '\n';
    return 0;
}