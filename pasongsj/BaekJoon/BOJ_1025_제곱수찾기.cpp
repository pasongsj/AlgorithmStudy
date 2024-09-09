#include <iostream>
#include <vector>
#include <string>
#include <cmath>
int n, m;


bool IsSquare(long long num)
{
	long long sq = static_cast<long long>(std::sqrt(num));

	return sq * sq == num;
}


long long GetNum(int i, int j, int k, int l, const std::vector<std::vector<int>>& arr)
{
	if (k == 0 && l == 0)
	{
		if (true == IsSquare(arr[i][j]))
		{
			return arr[i][j];
		}
		return -1;
	}
	std::string ans = std::to_string(arr[i][j]);

	long long res = -1;
	while (true)
	{
		long long curlongnum = std::stoll(ans);
		if (true == IsSquare(curlongnum))
		{
			res = curlongnum;
		}
		i += k;
		j += l;
		if (0 <= i && i < n && 0 <= j && j < m)
		{
			ans += std::to_string(arr[i][j]);
			continue;
		}
		break;
	}
	return res;
}


int main()
{
	std::cin >> n >> m;


	long long answer = -1;
	std::vector<std::vector<int>>arr;
	arr.resize(n);
	for (int i = 0;i < n;++i)
	{
		arr[i].resize(m);
		std::string line;
		std::cin >> line;
		for (int j = 0;j < m;++j)
		{
			arr[i][j] = line[j]-'0';
		}
	}

	for (int i = 0;i < n;++i)
	{
		for (int j = 0;j < m;++j)
		{

			for (int k = -i;k < n;++k)
			{
				for (int l = -j;l < m;++l)
				{
					long long cur =  GetNum(i, j, k, l, arr);
					if (cur > answer)
					{
						answer = cur;
					}

				}
			}

		}
	}
	std::cout << answer;
	return 0;
}
