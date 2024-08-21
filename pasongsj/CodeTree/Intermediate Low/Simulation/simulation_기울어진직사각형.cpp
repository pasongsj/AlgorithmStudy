#include <iostream>
#include <vector>
using namespace std;

std::vector<std::vector<int>> grid;

int n,answer;

bool InRange(int a,int b)
{
    return 0<=a && a<n && 0<=b && b<n;
}

int dx[4] = {-1,1,1,-1};
int dy[4] = {1,1,-1,-1};

void CalMax(int x, int y,int left, int right)
{
    if(true == InRange(x,y) && true == InRange(x-left,y+left) && true == InRange(x+right-left,y+right+left) && true == InRange(x+right,y+right))
    {
        int cnt = 0;
        for(int i=0;i<left;++i)
        {
            cnt += grid[x+dx[0]*i][y+dy[0]*i];
            cnt += grid[x+right-left + dx[2]*i][y+right+left+dy[2]*i];
        }
        for(int j=0;j<right;++j)
        {
            cnt += grid[x-left + dx[1] * j][y+left + dy[1] *j];
            cnt += grid[x+right + dy[3] * j][y+right +dy[3]*j];
        }
        answer = answer>cnt?answer:cnt;
    }
    else
    {
        return;
    }
    CalMax(x,y,left+1,right);
    CalMax(x,y,left,right+1);

}


int main() {

    std::cin>>n;
    grid.resize(n);

    for(int i=0;i<n;++i)
    {
        grid[i].resize(n);
        for(int j=0;j<n;++j)
        {
            std::cin>>grid[i][j];

        }
    }

    answer = 0;
    for(int i=1;i<n-1;++i)
    {
        for(int j=0;j<n-1;++j)
        {
            CalMax(i,j,1,1);
        }
    }


    std::cout<<answer;
    // 여기에 코드를 작성해주세요.
    return 0;
}