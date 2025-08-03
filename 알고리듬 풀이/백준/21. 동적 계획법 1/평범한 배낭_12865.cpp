/**
 * 백준 평범한 배낭_12865
 * 배낭 채우기 문제를 탐욕적 기법이 아닌 동적 계획법을 통해 풀이하자.
 * N개의 물건 중 T개를 선택하는데 각 물건들은 무게 W와 가치 V를 가지고 있다.
 * 최대 K만큼의 무게를 넣을 수 있을 때, 가치의 최대 값을 구하라.
 * 
 * 제한사항
 *****************************************
 * 0 < N <= 100                          *
 * 0 < K <= 100,000                      *
 * 0 < W <= 100,000                      *
 * -1 < V <= 1,000                       *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 1 + 15분
 */


#include <iostream>
#include <vector>

#define MAX_VALUE 100000

using namespace std;

static int N, K;

static vector<pair<int, int>> items;
static vector<int> maxValues; // 가방에 담긴 물건들의 가치 총 합

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;  // 물건 갯수, 배낭의 최대 무게

    items.reserve(N + 1);
    maxValues.resize(K + 1, 0);
    
    for (int i = 0; i < N; ++i)
    {
        int weight, value;  // 무게, 가치
        cin >> weight >> value;
        
        if (weight > K) 
        {
            continue;
        }
        
        items.emplace_back(weight, value);
    }

    for (int i = 0; i < N; ++i)
    {
        int weight = items[i].first, value = items[i].second;

        for (int j = K; j >= weight; --j)
        {
            // 뒤에서 부터 하면 최대한 많이 담으면서 가치가 높은것들만 담을 수 있음
            // 중복 방지를 위해 뒤에서부터 순회
            maxValues[j] = max(maxValues[j], maxValues[j - weight] + value);
        }
    }

    cout << maxValues[K] << '\n';

    return 0;
}