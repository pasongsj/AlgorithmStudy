#include <iostream>
#include <vector>

std::vector<bool> isvisited;
std::vector<int> res;

int DFS(int q, const std::vector<std::vector<int>>& links)
{
    int cnt = 1;
    for (int i = 0; i < links[q].size(); ++i)
    {
        int next = links[q][i];
        if (false == isvisited[next])
        {
            isvisited[next] = true;
            cnt += DFS(next, links);
        }
    }

    res[q] = cnt;
    return cnt;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, R, Q;
    std::cin >> N >> R >> Q;

    isvisited.resize(N + 1);
    res.resize(N + 1);

    std::vector<std::vector<int>> links(N + 1, std::vector<int>());
    for (int i = 0; i < N - 1; ++i)
    {
        int U, V;
        std::cin >> U >> V;
        links[U].push_back(V);
        links[V].push_back(U);
    }

    isvisited[R] = true;
    DFS(R, links);

    for (int i = 0; i < Q; ++i)
    {
        int num;
        std::cin >> num;
        std::cout << res[num] << '\n';
    }

    return 0;
}
