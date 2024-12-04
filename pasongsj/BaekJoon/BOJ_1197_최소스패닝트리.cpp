#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>



std::vector<int> parent;

int Getparent(int a)
{
    if (a == parent[a])
    {
        return a;
    }
    return parent[a] = Getparent(parent[a]);
}


void MakeUnion(int a, int b)
{
    int ap = Getparent(a);
    int bp = Getparent(b);
    if (ap < bp)
    {
        parent[bp] = ap;
    }
    else
    {
        parent[ap] = bp;
    }
}




bool IsCycle(int a, int b)
{
    int ap = Getparent(a);
    int bp = Getparent(b);
    return ap == bp;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    parent.resize(n + 1);
    std::vector<std::tuple<int, int, int>> lines;
    for (int i = 0; i < m; ++i)
    {
        int a, b, cost;
        std::cin >> a >> b >> cost;
        lines.push_back(std::make_tuple(a, b, cost));
    }
    std::sort(lines.begin(), lines.end(), [](const std::tuple<int, int, int> a, const std::tuple<int, int, int> b)
        {
            return (std::get<2>(a)) < (std::get<2>(b));
        });

    for (int i = 1; i <= n; ++i)
    {
        parent[i] = i;
    }

    int ans = 0;
    for (const std::tuple<int, int, int> line : lines)
    {
        int a, b, cost;
        std::tie(a, b, cost) = line;
        if (true == IsCycle(a,b))
        {
            continue;
        }
        ans += cost;
        MakeUnion(a, b);
    }
    std::cout << ans;
    return 0;
}
