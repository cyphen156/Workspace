/**
 * 백준 줄 세우기_2252
 * N명의 학생을 키 순서대로 줄을 세워야 하는데 키를 모른다. 
 * 일부만 키를 비교해서 결과가 주어질 때 줄 세우는 프로그램을 만들어라.
 * ==> 크기를 직접 비교할 수 없는 대신 상대적인 관계가 주어진다는 소리이다.
 * 첫째 줄에 학생들을 앞에서부터 줄을 세운 결과를 출력한다. 답이 여러 가지인 경우에는 아무거나 출력한다.
 * 
 * 
 * 제한사항
 *****************************************
 * 1 <= N < 32,001 (Count)               *
 * 1 <= M <  100,001 (results)           *
 * A is Smaller than B                   *
 * A and B is student number             *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 5 + 90분
 */


#include <iostream>
#include <queue>
#include <vector>

using namespace std;

static const int MAX_STUDENT_COUNT = 32001;
static const int MAX_COMPAIR_COUNT = 100001;

static int N, M;

static int front[MAX_STUDENT_COUNT] = { 0 };    // 앞에 있어야 하는 학생 수
static vector<int> back[MAX_STUDENT_COUNT];     // 간선 인덱스

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; ++i)
    {
        int A, B;
        cin >> A >> B;
        front[B]++;
        back[A].push_back(B);
    }

    queue<int> q;
    // 만약 나보다 앞에 있는 애가 없다 
    // == 인덱스 순으로 정렬됨
    for (int i = 1; i <= N; ++i)
    {
        if (front[i] == 0)
        {
            q.push(i);
        }
    }

    bool isFirst = true;

     while (!q.empty())
    {
        int u = q.front(); q.pop();

        if (!isFirst) cout << ' ';
        isFirst = false;
        cout << u;

        for (size_t k = 0; k < back[u].size(); ++k)
        {
            int v = back[u][k];
            if (--front[v] == 0) q.push(v);
        }
    }
    cout << endl;
    return 0;
}