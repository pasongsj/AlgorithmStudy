#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

bool InRange(int a,int b, int n)
{
    return 0<=a && a<n && 0<=b && b<n;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    std::cin>>n;
    std::vector<std::vector<int>>arr;
    std::vector<std::vector<int>> dp;
    arr.resize(n);
    dp.resize(n);
    std::priority_queue<std::pair<int,std::pair<int,int>>> pq;
    for(int i=0;i<n;++i)
    {
        arr[i].resize(n);
        dp[i].resize(n);
        for(int j=0;j<n;++j)
        {
            std::cin>>arr[i][j];
            dp[i][j] = 1;
            pq.push(std::make_pair(-arr[i][j],std::make_pair(i,j)));
        }
    }

    const int dx[4] = {-1,0,0,1};
    const int dy[4] = {0,1,-1,0};
    int answer = 0;
    while(!pq.empty())
    {
        std::pair<int,int> cur = pq.top().second;
        pq.pop();
        for(int i=0;i<4;++i)
        {
            int nx = cur.first+ dx[i];
            int ny = cur.second + dy[i];
            if(true == InRange(nx,ny,n)&& arr[cur.first][cur.second]<arr[nx][ny] && dp[cur.first][cur.second]+1>dp[nx][ny])
            {
                dp[nx][ny] = dp[cur.first][cur.second]+1;
                answer = answer > dp[nx][ny]?answer:dp[nx][ny];
            }
        }
    }
    std::cout<<answer;
    return 0;
}
