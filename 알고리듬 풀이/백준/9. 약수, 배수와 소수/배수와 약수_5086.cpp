/**
 * 백준 배수와 약수_5086
 * 두 수가 주어졌을 때 어떠한 관계인지 구하는 프로그램
 * 출력예시
 * 첫 번째 숫자가 두 번째 숫자의 약수이다. ==  factor
 * 첫 번째 숫자가 두 번째 숫자의 배수이다. == multiple
 * 첫 번째 숫자가 두 번째 숫자의 약수와 배수 모두 아니다. ==  neither
 * 
 * 제한사항
 *****************************************
 * Input1 != Input2                      *
 * 0 <= Input1, Input2 <= 10,000         *
 * Last Input always 0, 0                *
 *****************************************
 *
 *
 *
 * 주의
 * 테스트 케이스의 제한조건이 입력으로 설정되어 있으므로 0, 0이 입력되는 조건을 주의한다.
 * 
 * 풀이시간 5분
 */


#include <iostream>
#include <string>

enum results
{
    factor,
    multiple,
    neither  
};

using namespace std;

int main(void)
{
    while(1)
    {
        int input1, input2;
        cin >> input1 >> input2;
        if ((input1 == 0) && (input2 == 0))
        {
            break;
        }
        int temp;
        string str = "";
        if (input1 > input2)
        {   // possible :: multiple
            temp = input1 % input2;
            str = "multiple";
        }
        else 
        {   // possible :: factor
            temp = input2 % input1;
            str = "factor";
        }
        if (temp != 0)
        {
            str = "neither";
        }
        cout << str << endl;
    }
    return 0;
}