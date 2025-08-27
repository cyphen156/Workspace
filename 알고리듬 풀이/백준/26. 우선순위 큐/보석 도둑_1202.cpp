/**
 * 백준 보석 도둑_1202
 * N개의 보석이 있다.
 * 각 보석은 Mi의 무게와 가격 Vi를 가지고 있는데, 
 * Ci 만큼의 무게를 담을 수 있는 가방이 K개 있다.
 * 또한 한 개의 가방에 보석을 한개만 담을 수 있다.
 * 보석의 최대 가격을 구하라.
 * 
 * 
 * 제한사항
 *****************************************
 * 1 <= N, K < 300,001                   *
 * 0 <= Mi, Vi < 1,000,001               *
 * 1 <= Ci < 100,000,001                 *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 3 + 30분
 */


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

static const int MAX_COUNT = 300001;
static const int MAX_VALUE = 1000001;
static const int MAX_CARRAGE = 100000001;

using namespace std;

static int N, K;

vector<pair<int, int>> jewel;
static priority_queue<int, vector<int>, greater<int>> backpack;    // minheap
static priority_queue<int> candidates;

static long long sum = 0;

bool Compair(const pair<int, int>&left, const pair<int, int>&right);
void Calculate();

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;

    jewel.resize(N);
    
    for (int i = 0; i < N; ++i)
    {
        int mass, value;
        cin >> mass >> value;
        jewel[i].first = mass;
        jewel[i].second = value;
    }

    for (int i = 0; i < K; ++i)
    {
        int capacity;
        cin >> capacity;
        backpack.push(capacity);
    }
    
    Calculate();
    cout << sum << '\n';

    return 0;
}

bool Compair(const pair<int, int>&left, const pair<int, int>&right)
{
    // 무게 먼저 비교
    if (left.first != right.first)
    {
        return left.first < right.first;
    }

    // 무게 같으면 가치 비교
    return left.second < right.second;
}
void Calculate()
{
    sort(jewel.begin(), jewel.end(), Compair);

    int index = 0;

    while (backpack.empty() != true)
    {
        int capacity = backpack.top();
        backpack.pop();

        while (index < N && jewel[index].first <= capacity)
        {
            candidates.push(jewel[index].second);
            ++index;
        }

        if (!candidates.empty())
        {
            sum += static_cast<long long>(candidates.top());
            candidates.pop();
        }
    }
}

