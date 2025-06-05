/**
 * 백준 가로수_2485
 * 주어진 자료에서 거리를 측정하여 최소 간격을 찾아 비어있는 부분에 추가로 자료를 넣어 같은 간격으로 채우기
 * 
 * 제한사항
 *****************************************
 * 2 < N(Input Size) <= 100,000          *
 * 0 < InputCase <= 1,000,000,000        *
 * There is No Duplicate                 *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 60분
 */


#include <iostream>
#include <algorithm>

using namespace std;

static int arr[100000];
static int dist[100000];

int GCD(int a, int b);
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;

    cin >> N;
    
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    
    // 거리 차이 찾기
    for (int i = 0; i < N-1; ++i)
    {
        dist[i] =  arr[i+1] - arr[i];
    }
    
    int minDist = dist[0];
    for (int i = 0; i < N-1; ++i)
    {
        minDist = GCD(minDist, dist[i]);
    }
    
    int count = 0;
    for (int i = 0; i < N-1; ++i)
    {
        count += (dist[i] / minDist) -1;
    }
    cout << count << '\n';
    return 0;
}

int GCD(int a, int b)
{
    while(b != 0)
    {
        int temp = a % b;
        a = b;
        b= temp;
    }
    return a;
}
