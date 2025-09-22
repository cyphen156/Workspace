#include <stack>
#include <vector>

void DFS(int start, const std::vector<std::vector<int>>& g)
{
    std::stack<int> st;
    std::vector<bool> isVisited(g.size(), false);

    st.push(start);
    
    while (!st.empty())
    {
        int current = st.top();
        st.pop();
        
        if (isVisited[current])
        {
            continue;
        }

        isVisited[current] = true;

        // 전위 순회를 위한 역순 푸시
        for (int i = g[current].size() - 1; i >= 0; --i)
        {
            int next = g[current][i];
            if (!isVisited[next]) 
            {
                st.push(next);
            }
        }
    }
}