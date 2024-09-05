#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int t;
	std::cin >> t;
	std::vector<int> answer;
	while (t--)
	{
		int n;
		std::cin >> n;
		std::vector<std::vector<int>> arr;
		std::vector <std::vector<int>> dp;
		arr.resize(2);
		dp.resize(2);
		for (int i = 0;i < 2; ++i)
		{
			arr[i].resize(n);
			dp[i].resize(n);
			for (int j = 0;j < n; ++j)
			{
				std::cin >> arr[i][j];
				dp[i][j] = arr[i][j];
			}
		}
		dp[1][1] += arr[0][0];
		dp[0][1] += arr[1][0];

		for (int i = 2;i < n;++i)
		{
			dp[1][i] += std::max(dp[0][i - 1], dp[0][i - 2]);
			dp[0][i] += std::max(dp[1][i - 1], dp[1][i - 2]);
		}

		answer.push_back(std::max(dp[0][n - 1], dp[1][n - 1]));
	}

	for (int ans : answer)
	{
		std::cout << ans << std::endl;
	}
}
