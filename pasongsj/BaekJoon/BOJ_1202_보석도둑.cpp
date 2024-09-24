#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <set>

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::priority_queue<std::pair<int, int>> pq;
    for (int i = 0; i < n; ++i)
    {
        int m, v;
        std::cin >> m >> v;
        pq.push(std::make_pair(v, m));
    }
    int c;
    std::multiset<int> bags;
    for (int j = 0; j < k; ++j)
    {
        std::cin >> c;
        bags.insert(c);
    }

    long long answer = 0;

    while (!pq.empty())
    {
        int m, v;
        std::tie(v, m) = pq.top();
        pq.pop();
        auto it = bags.lower_bound(m);
        if (it == bags.end())
        {
            continue;
        }
        answer += v;
        bags.erase(it);
    }
    std::cout << answer;
    return 0;
}
