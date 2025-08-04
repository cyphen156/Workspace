/**
 * 백준 인간-컴퓨터 상호작용_16139
 * 문자열을 입력받아 
 * 문자열의 구간[l, r]에서 
 * 특정 알파벳이 a가 등장한 횟수를 세는 프로그램을 만들어라.
 * 
 * 문제 해결 전략 
 * 알파벳마다 누산합 배열을 만들어 놓는다.
 * 
 * 제한사항
 *****************************************
 * String S                              *
 * 0 < S.length() <= 200,000             *
 * Alpha is always lowerCase             *
 * sector is from l to r                 *
 * -1 < l <= r < | S |                   *
 * repeatCount q                         *
 * 0 < q <= 200,000                      *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 5 + 10분
 */


#include <iostream>

#define ALPHACOUNT 26
#define MAX_SIZE 200001

using namespace std;

static int q;
static string str;
static int prefixSum[ALPHACOUNT][MAX_SIZE];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력부
    str.reserve(MAX_SIZE);
    cin >> str;

    // 문자열 전처리
    int n = str.length();

    for (int ch = 0; ch < ALPHACOUNT; ++ch) 
    {
        int cnt = 0;
        for (int i = 0; i < n; ++i) 
        {
            if (str[i] - 'a' == ch)
            {
                cnt++;
            } 
            prefixSum[ch][i + 1] = cnt;
        }
    }

    // 질의부
    cin >> q;
    
    for (int i = 0; i < q; ++i)
    {
        char alpha;
        int l, r;
        cin >> alpha >> l >> r;

        int index = alpha - 'a';

        // 출력부
        cout << prefixSum[index][r+1] - prefixSum[index][l] << '\n';
    }
    
    return 0;
}