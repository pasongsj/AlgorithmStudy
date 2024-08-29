#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    std::vector<long long> points;
    int n, q;
    std:: cin >> n >> q;
    points.resize(n+2);
    for(int i=1;i<=n;++i)
    {
        std::cin>>points[i];
    }
    
    points[n+1] = 1000000001;
    points[0] = -1000000001;
    std::sort(points.begin(),points.end());
    std::vector<int> answer;
    answer.resize(q);

    for(int j=0;j<q;++j)
    {
        int s, e;
        std::cin >> s >> e;
        if(s > e)
        {
            continue;
        }
        int endp = (std::upper_bound(points.begin(),points.end(),e)-points.begin());
        int startp = std::lower_bound(points.begin(),points.end(),s)-points.begin();
        answer[j] = endp-startp;
    }

    for(int ans : answer)
    {
        std::cout<<ans<<'\n';
    }
    return 0;
}
