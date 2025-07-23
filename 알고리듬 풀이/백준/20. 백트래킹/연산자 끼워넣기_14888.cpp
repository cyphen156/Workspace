/**
 * 백준 연산자 끼워넣기_14888
 * 수열을 먼저 주고, 그 안에 연산을 도와줄 연산자를 줄 때
 * 만들 수 있는 식의 결과가 최대인 것과 최소인 것을 구하는 프로그램을 작성하시오.
 * ex) 입력 예시
 * 5
 * 1 2 3 4 5 
 * 1 1 1 1 
 * 이 입력을 조합하면 다음과 같은 수식이 완성된다.
 * 1 + 2 - 3 × 4 ÷ 5
 * 식의 계산은 연산자 우선순위를 무시하고 앞에서부터 진행한다
 * --> FIFO
 * 나눗셈 연산시 나머지는 버린다.
 * 음수를 양수로 나눌때는 양수로 바꾸어 나눈뒤 다시 음수로 바꾸는 방식을 사용한다.
 * 수의 순서는 바꿀 수 없지만 연산자의 순서는 변경할 수 있다.
 * 
 * 제한사항
 *****************************************
 * 1 < N < 11                            *
 * 0 < Input <= 100                      *
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
#include <cmath>

static int N, minValue = 0x7FFFFFFF, maxValue = 0x80000000, cnt = 0;
static int numbers[11] = { 0 } ;
static int operationCounts[4] = { 0 };

void BackTrack(int depth);

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    BackTrack(0);

    cout << maxValue << '\n';
    cout << minValue << '\n';

    return 0;
}

void BackTrack(int depth)
{
    
}
