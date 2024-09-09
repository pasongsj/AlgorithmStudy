#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int n, d, c;
        std::cin >> n >> d >> c;
        std::vector<std::vector<std::pair<int,int>>> arr;
		std::vector<int> Isinfected(n + 1, -1);
        arr.resize(n + 1);

        for(int i=0;i<d;++i)
        {
            int a, b, s;
            std::cin >> a >> b >> s;
            arr[b].push_back(std::make_pair(a, s));
        }
        std::queue<std::pair<int,int>> q;
        q.push(std::make_pair(c,0));
        Isinfected[c] = 0;
        while (!q.empty())
        {
            int cur, cur_cnt;
            std::tie(cur, cur_cnt) = q.front();
            q.pop();
            for (std::pair<int,int> next : arr[cur])
            {
                if (-1 == Isinfected[next.first] || Isinfected[next.first] > cur_cnt + next.second)
                {
                    next.second += cur_cnt;
                    Isinfected[next.first] = next.second;
                    q.push(next);
                }
            }
        }
        int cnt = 0;
        int second = 0;
        for (int i = 1;i <= n;++i)
        {
            if (Isinfected[i] == -1)
            {
                continue;
            }
            cnt++;
            second = second > Isinfected[i] ? second : Isinfected[i];
        }
        std::cout << cnt << ' ' << second << '\n';
    }

}
