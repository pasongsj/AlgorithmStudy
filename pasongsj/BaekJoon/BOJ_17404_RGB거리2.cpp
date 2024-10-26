#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
int n;

long long MinSum(int startindex, const std::vector<std::vector<int> > & pr)
{
	std::vector<std::vector<long long>> dps(n, std::vector<long long>(3, INT_MAX));
    dps[0][startindex] = pr[0][startindex];
	for(int i=1;i<n;++i)
    {
		dps[i].resize(3);
        dps[i][0] = std::min(dps[i-1][1], dps[i-1][2]) + pr[i][0];
        dps[i][1] = std::min(dps[i-1][0], dps[i-1][2]) + pr[i][1];
		dps[i][2] = std::min(dps[i-1][0], dps[i-1][1]) + pr[i][2];
	}

	return std::min(dps[n-1][(startindex+1)%3], dps[n-1][(startindex+2)%3]);
}


int main()
{
	std::cin >> n;
	std::vector<std::vector<int>> prices;
	prices.resize(n);
	for(int i = 0; i < n; ++i)
	{
		prices[i].resize(3);
		std::cin >> prices[i][0] >> prices[i][1] >> prices[i][2];
	}

	long long answer = INT_MAX;
	for(int i=0;i<3;++i)
	{
		answer = std::min(answer, MinSum(i,prices));
	}
	std::cout<<answer;
	return 0;

}
