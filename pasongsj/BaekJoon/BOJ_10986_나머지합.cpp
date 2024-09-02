#include <iostream>
#include <vector>
#include <cmath>

int main()
{
	int n,m;
	std::cin >> n >> m;
	std::vector<long long> arr;
	std::vector<long long> remain_dp;
	std::vector<long long> remain_cnt;
	

	arr.resize(n+1);
	remain_dp.resize(n+1);
	remain_cnt.resize(m);
	for(int i=1;i<=n;++i)
	{
		std::cin>>arr[i];
		remain_dp[i] = (remain_dp[i-1]+arr[i])%m;
		remain_cnt[remain_dp[i]]++;
	}


	long long answer = remain_cnt[0];

	for(int i=0;i<m;++i)
	{
		answer += remain_cnt[i] * (remain_cnt[i] - 1) / 2;
	}

	std::cout<<answer<<std::endl;
	return 0;
}
