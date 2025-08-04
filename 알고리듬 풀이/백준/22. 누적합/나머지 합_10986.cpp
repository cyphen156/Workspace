/**
 * 백준 나머지 합_10986
 * N개의 수가 주어졌을 때, 
 * 연속된 부분 구간의 합이 M으로 나누어 떨어지는 구간의 개수를 구하는 프로그램을 작성하라.
 * 
 * 제한사항
 *****************************************
 * 0 < N <= 1,000,000                    *
 * 1 < M <= 1,000                        *
 * -1 < number <= 1,000,000,000          *
 *****************************************
 *
 *
 *
 * 주의
 * 최대 누산 합의 값은 1,000 * 1,000,000,000 이므로 long long int 자료형을 사용한다.
 * ==> Modulor 연산을 누산합에서 처리하면 int자료형 만으로 충분하다. (Data 압축)
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 3 + 30분
 */


#include <iostream>

#define MAX_SIZE        1000001
#define MAX_SECTOR_SIZE 1001
using namespace std;

static int N, M;    // M is divisor
static int numbers[MAX_SIZE] = { 0 };
static int modCount[MAX_SECTOR_SIZE] = {0};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // 입력부
    cin >> N >> M;

    long long cnt = 0;
    int prefixSum = 0;
    modCount[0] = 1;

    for (int i = 0; i < N; ++i)
    {
        cin >> numbers[i];
        
        prefixSum = (prefixSum + numbers[i]) % M;

        int index = prefixSum;
        
        cnt += modCount[index];
        modCount[index]++;
    }


    cout << cnt << '\n';
    return 0;
}