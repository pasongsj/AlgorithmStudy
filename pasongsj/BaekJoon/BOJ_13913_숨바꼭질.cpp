#include <iostream>
#include <vector>
#include <queue>
#include <deque>

bool InRange(int a, int m)
{
    return 0 <= a && a <= m;
}


int main()
{
    const int maxnum = 100000;
    std::vector<int> arr(maxnum+1, maxnum+2);
    std::vector<int> lastvisited(maxnum + 1, -1);
    int n, k;
    std::cin >> n >> k;
    arr[n] = 0;

    std::queue<int> q;
    q.push(n);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        if (true == InRange(cur - 1, maxnum) && arr[cur - 1] > arr[cur] + 1)
        {
            arr[cur - 1] = arr[cur] + 1;
            lastvisited[cur - 1] = cur;
            q.push(cur - 1);
        }
        if (true == InRange(cur + 1, maxnum) && arr[cur + 1] > arr[cur] + 1)
        {
            arr[cur + 1] = arr[cur] + 1;
            lastvisited[cur + 1] = cur;
            q.push(cur + 1);
        }
        if (true == InRange(2 * cur, maxnum) && arr[2 * cur] > arr[cur] + 1)
        {
            arr[2 * cur] = arr[cur] + 1;
            lastvisited[2 * cur] = cur;
            q.push(2 * cur);
        }
    }
	std::cout << arr[k] << std::endl;

    std::deque<int> dq;
    while (true)
    {
        dq.push_front(k);
        if (lastvisited[k] == -1)
        {
            break;
        }
        k = lastvisited[k];
    }
    
    for (int ans : dq)
    {
        std::cout << ans << ' ';
    }


    return 0;
}
