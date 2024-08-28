#include <iostream>
#include <vector>
using namespace std;

int answer;

void Permute(int index, int n,int sum,std::vector<bool>& _visited, const std::vector<std::vector<int>>& arr)
{
    if(index == n)
    {
        answer = answer>sum?answer:sum;
        return;
    }
    for(int i=0;i<n;++i)
    {
        if(false == _visited[i])
        {
            _visited[i] = true;
            Permute(index+1,n,sum+arr[index][i],_visited,arr);
            _visited[i] = false;
        }
    }
}

int main() {
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
    std::vector<bool> isvisited(n,false);

    answer = 0;
    Permute(0,n,0,isvisited,arr);
    std::cout<<answer;
    // 여기에 코드를 작성해주세요.
    return 0;
}
