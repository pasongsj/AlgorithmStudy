#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    std::vector<int> dp;
    int n;
    std::cin>>n;
    dp.resize(n+1>3?n+1:3);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3;i<=n;++i)
    {
        dp[i] += (dp[i-1] + dp[i-2]) % 10007;
    }
    std::cout<<dp[n];
    return 0;
}
