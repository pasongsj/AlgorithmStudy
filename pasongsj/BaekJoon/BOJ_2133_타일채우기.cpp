#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> dp;

    int k = n + 1 > 5 ? n + 1 : 5;
	dp.resize(k);
    dp[0] = 1;
    dp[2] = 3;
    dp[3] = 0;
    dp[4] = 9+2;
    for (int i = 6;i <= n;i += 2)
    {
        dp[i] = dp[i - 2] * 3;
        for (int j = i - 4;j >= 0;j -= 2)
        {
            dp[i] += dp[j] * 2;
        }
    }

    dp[0] = 0;
    std::cout << dp[n];
   

    return 0;
    
}
