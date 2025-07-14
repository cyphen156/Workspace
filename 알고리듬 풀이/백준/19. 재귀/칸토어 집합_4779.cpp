/**
 * 백준 칸토어 집합_4779
 * 칸토어 집합은 [0, 1] 사이의 실수 집합이다.
 * 각 스탭마다 구간을 3등분하여 가운데 구간을 제외한다.
 * Ex) [0, 0.33], [0.331, 0.66], [0.661, 1]과 같이 분할하고 가운데 부분을 제외한다.
 * 모든 선의 길이가 1일 때 까지 반복한다.
 * Default
 * ---------------------------
 * Step1
 * ---------         ---------
 * Step2
 * ---   ---         ---   ---
 * Step3
 * - -   - -         - -   - -
 * 3분할 분할 정복 기법
 * L, M, R
 * 
 * if (size == 3)
 * return;
 * 
 * 제한사항
 *****************************************
 * 0 <= N <= 12                          *
 * string length is 3^N                  *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 0분
 */

#define MAX_LENGTH 1000000

#include <iostream>
#include <cmath>

using namespace std;

static char str[MAX_LENGTH] = {'\0'};
static char result[MAX_LENGTH] = {'\0'};

void CantorSet(int left, int right);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    while (cin >> N)
    {
        // 문자열 초기화
        int length = pow(3, N);
        for (int i = 0; i < length; ++i)
        {
            str[i] = '-';
        }

        CantorSet(0, length - 1);

        for (int i = 0; i < length; ++i)
        {
            cout << str[i];
        }

        cout << '\n';
    }

    return 0;
}

void CantorSet(int left, int right)
{
    if (right - left < 1)
    {
        return;
    }  

    int third = (right - left + 1) / 3;
    if (third == 0) return;

    int lMid = left + third;
    int rMid = left + 2 * third;

    for (int i = lMid; i < rMid; ++i)
    {
        str[i] = ' ';
    }

    CantorSet(left, lMid - 1);
    CantorSet(rMid, right);
}