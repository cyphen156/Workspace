/**
 * 백준 숫자 카드 2_10816
 * N개의 정수 배열이 있다.
 * 이중 M개의 정수를 입력받았을 때 존재하는 숫자 개수를 구하라. 
 * 
 * 제한사항
 *****************************************
 * 1 <= N, M < 500,001                   *
 * -10,000,000 <= value < 10,000,001     *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 1 + 5분
 */


#include <iostream>

using namespace std;

static const int MAX_SIZE   = 20000001;
static const int OFFSET     = 10000000;

static int N, M;
static int inputs[MAX_SIZE] = { 0 };

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int input;
        cin >> input;
        inputs[input + OFFSET]++;
    }

    cin >> M;

    for (int i = 0; i < M; ++i)
    {
        int input;
        cin >> input;
        cout << inputs[input + OFFSET] << ' ';
    }
    cout << endl;
    return 0;
}