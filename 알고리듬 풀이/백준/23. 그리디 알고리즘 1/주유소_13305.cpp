/**
 * 백준 주유소_13305
 * N개의 노드들을 1차원 배열을 통해 연결한다. Node == City
 * 각 노드끼리의 연결에는 거리가 존재한다. length
 * 시작 노드부터 끝 노드까지 방문해야 한다.
 * 사용자는 이동할 수 있는 이동 가능 거리를 가지고 있다. 
 * 각 노드를 방문할 때마다 이동할 수 있는 이동 가능 거리를 충전할 수 있다. 
 * 노드마다 충전할 이동 가능 거리를 충전하는데 드는 비용은 서로 다르다.
 * 이 비용이 최소가 되도록 하는 프로그램을 작성하라.
 * 
 * 제한사항
 *****************************************
 * 2 <= N < 100,001 (Cities)             *
 * 1 <= length < 1,000,000,001           *
 * 1 <= chargeCost < 1,000,000,001       *
 *****************************************
 *
 *
 *
 * 주의
 * 기름값은 도시별로 다르므로,
 * 항상 지금까지의 최소 주유 가격을 유지하면서
 * 앞으로 갈 거리를 커버할 수 있도록 주유 전략을 세운다.
 * 뒤의 도시 가격이 더 싸다고 해도 미리 전부 주유하지 않는다.
 * 대신 현재까지의 최소 가격으로 당장의 이동 거리만큼만 주유한다.
 * 현실적 이동이 아니라 최적화 관점의 알고리즘 설계임.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 5 + 10분
 */


#include <iostream>

#define MAX_SIZE    100001
#define MAX_VALUE   1000000000

using namespace std;

static int N;
static int lengths[MAX_SIZE] = { 0 };
static int chargeCosts[MAX_SIZE] = { 0 };

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    for (int i = 0; i < N - 1; ++i)
    {
        cin >> lengths[i];
    }

    for (int i = 0; i < N; ++i)
    {
        cin >> chargeCosts[i];
    }

    long long int maxCost = 0;
    long long int currentCost = MAX_VALUE;

    for (int i = 0; i < N - 1; ++i)
    {
        if (currentCost > chargeCosts[i])
        {
            currentCost = chargeCosts[i];
        }
        maxCost += currentCost * lengths[i];
    }

    cout << maxCost << '\n';
    return 0;
}