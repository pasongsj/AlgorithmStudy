#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>



int main()
{
	std::vector<long long> water;

	int n;
	std::cin >> n;
	water.resize(n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> water[i];
	}

	std::vector<long long> answer;
	answer.resize(2);

	long long diff = LLONG_MAX;
	
	int left = 0, right = n - 1;
	while (left < right)
	{
		if (diff > abs(water[left] + water[right]))
		{
			answer[0] = water[left];
			answer[1] = water[right];
			diff = abs(water[left] + water[right]);
		}
		if (abs(water[left]) < abs(water[right]))
		{
			right--;
		}
		else
		{
			left++;
		}
	}

	std::cout << answer[0] << ' ' << answer[1];
	return 0;
}
