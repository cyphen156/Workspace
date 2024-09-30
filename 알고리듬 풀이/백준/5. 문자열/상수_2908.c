/**
* 백준 2908 상수
* 두 수를 입력받고 입력받은 자릿수를 역순으로 바꾼 후 비교하여 큰 수를 출력하면 된다.
* 이 문제의 핵심은 입력 데이터의 강제 형변환 또는 자릿수 파싱, 그리고 비교 연산이다.
* 
* 
* 제한사항
*****************************************
* 0 < Input < 1,000                     *
*****************************************
*
*
*
* 주의
* 없다.
* 
* 풀이시간 30분
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int first, second, temp = -1;
    char result[3] = {0};

	scanf("%d %d", &first, &second);

    // 자릿수 파싱
    for (int i = 0; i < 3; ++i)
    {   
        // 나머지 연산을 통해 한자리 수 비교
        int a = first%10, b = second%10;
 
        // 다음 연산을 위한 자릿수 다운
        first /= 10;
        second /= 10;

        if (temp != -1)
        {
            result[i] = (temp % 10) + '0';;
            temp /= 10;
            continue;
        }

        if(a > b)
        {
            temp = first;
            result[i] = a + '0';
        }
        else if(a < b)
        {
            temp = second;
            result[i] = b + '0';
        }
        else 
        {
            result[i] = a + '0';
        }
    }

    printf("%s\n", result); 
    return 0;
}