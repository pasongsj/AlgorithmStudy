#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,1,-1};

bool InRange(int x, int y,int n)
{
    return 0<=x && x<n && 0<=y && y<n;
}

bool Cancolor(int n, int gap, const std::vector<std::vector<int>>& arr)
{
    
    std::vector<std::vector<bool>> isvisted(n,std::vector<bool>(n,false));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(true == isvisted[i][j])
            {
                continue;
            }
            int cnt = 0;
            std::queue<std::pair<int,int>> q;
            q.push(std::make_pair(i,j));
            isvisted[i][j] = true;

            while(!q.empty())
            {
                int cx,cy;
                std::tie(cx,cy) = q.front();
                q.pop();
                cnt++;
                for(int k=0;k<4;++k)
                {
                    int nx = cx + dx[k];
                    int ny = cy + dy[k];
                    
                    if(true == InRange(nx,ny,n) &&
                    false == isvisted[nx][ny] &&
                    abs(arr[cx][cy]-arr[nx][ny])<=gap)
                    {           
                        isvisted[nx][ny] = true;
                        q.push(std::make_pair(nx,ny));
                    }

                }
            }

            if(cnt >= (n*n+1)/2)
            {
                return true;
            }
        }
    }
    return false;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    std::cin>>n;
    std::vector<std::vector<int>> arr;
    arr.resize(n);
    for(int i=0;i<n;++i)
    {
        arr[i].resize(n);
        for(int j=0;j<n;++j)
        {
            std::cin>>arr[i][j];
        }
    }
    int start = 0, end = 1000000;
    int answer = 0;
    while(start<=end)
    {
        int mid = (start+end)/2;
        if(Cancolor(n,mid,arr))
        {
            answer = mid;
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }

    std::cout<<answer;
    return 0;
}
