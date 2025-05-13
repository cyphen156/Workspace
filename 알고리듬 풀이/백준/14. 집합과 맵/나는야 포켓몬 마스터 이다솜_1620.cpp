/**
 * 백준 나는야 포켓몬 마스터 이다솜_1620
 * 잡소리가 굉장히 많다.
 * 문자열을 인덱스 번호로 반환하거나 인덱스 번호를 이름으로 출력하는 프로그램을 만들어라.
 * 
 * 제한사항
 *****************************************
 * 0 < N, M <= 100,000                   *
 * 1 < Name <= 20                        *
 * Input Case : String || Int            *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 20분
 */


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Pokemon 
{
    string name;
    int index;
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    Pokemon* pokemons = new Pokemon[N + 1];    
    Pokemon* sortedPokemons = new Pokemon[N + 1];

    for (int i = 1; i <= N; i++)
    {
        cin >> pokemons[i].name;
        pokemons[i].index = i;
        sortedPokemons[i] = pokemons[i];
    }

    // 포켓몬 이름을 정렬한다.
    sort(sortedPokemons + 1, sortedPokemons + N + 1, [](const Pokemon& a, const Pokemon& b) {
        return a.name < b.name;
    });

    for (int i = 1; i <= M; i++)
    {
        string input;
        cin >> input;

        // 인덱스 번호로 입력받은 경우
        if (isdigit(input[0]))
        {
            int idx = stoi(input);
            cout << pokemons[idx].name << '\n';
        }

        // 이름으로 입력받은 경우
        // 이진 탐색을 통해 이름을 찾는다.
        int left = 1, right = N;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (sortedPokemons[mid].name == input)
            {
                cout << sortedPokemons[mid].index << '\n';
                break;
            }
            else if (sortedPokemons[mid].name < input)
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return 0;
}