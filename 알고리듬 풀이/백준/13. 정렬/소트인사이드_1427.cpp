/**
 * 백준 소트인사이드_1427
 * 
 * 그 수의 각 자리수를 내림차순으로 정렬하기
 * 수를 분해해서 가장 높은 수가 자릿수가 올라간다는 것이 핵심이다.
 * --> 문자열 파싱을 통해 해결 할 수 있다.
 * + 계수 정렬을 사용할 수 있다.
 * 
 * 제한사항
 *****************************************
 * 0 < N <= 1,000,000,000                *
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
#include <stdio.h>
using namespace std;

#define MAXVALUE 10

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int cnt[10] = { 0 };
    
    while (true)
    {
        char ch;
        scanf("%c", &ch);
        if (ch == '\n')
        {   
            break;
        }

        cnt[ch - '0']++;        
    }

    for (int i = 9; i >= 0; --i)
    {
        while(cnt[i] > 0)
        {
            cout << i;
            cnt[i]--;
        }
    }
    return 0;
}