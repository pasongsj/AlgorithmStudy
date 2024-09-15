#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>

int main()
{
	std::vector<std::vector<int>> taws;
	std::vector<int> twvpoints;
	taws.resize(5);
	twvpoints.resize(5);

	for (int i = 1; i < 5; ++i)
	{
		taws[i].resize(8);
		std::string tmp;
		std::cin >> tmp;
		for (int j = 0; j < 8; ++j)
		{
			taws[i][j] = tmp[j] - '0';
		}
	}

	int t;
	std::cin >> t;
	while (t--)
	{
		int index, dir;
		std::cin >> index >> dir;
		std::vector<bool> isvisited(5, false);
		std::queue<std::pair<int, int>> q;

		q.push(std::make_pair(index, dir));
		isvisited[index] = true;
		
		while (!q.empty())
		{
			int ctaw,cdir;
			std::tie(ctaw,cdir) = q.front();
			q.pop();

			if (0 < ctaw + 1 && ctaw + 1 < 5 && false == isvisited[ctaw + 1])
			{
				int ctwv = twvpoints[ctaw];
				int rtwv = twvpoints[ctaw + 1];
				if (taws[ctaw][(ctwv + 2) % 8] != taws[ctaw + 1][(rtwv + 6) % 8])
				{
					q.push(std::make_pair(ctaw + 1, cdir * -1));
				}
				isvisited[ctaw + 1] = true;
			}

			if (0 < ctaw - 1 && ctaw - 1 < 5 && false == isvisited[ctaw - 1])
			{
				int ctwv = twvpoints[ctaw];
				int ltwv = twvpoints[ctaw - 1];
				if (taws[ctaw][(ctwv + 6) % 8] != taws[ctaw - 1][(ltwv + 2) % 8])
				{
					q.push(std::make_pair(ctaw - 1, cdir * -1));
				}
				isvisited[ctaw - 1] = true;
			}

			twvpoints[ctaw] = (twvpoints[ctaw] - cdir + 8) % 8;

		}
	}
	int answer = 0;
	int point = 1;
	for (int i = 1; i < 5; ++i)
	{
		int twv = twvpoints[i];
		if (taws[i][twv] == 1)
		{
			answer += point;
		}
		point *= 2;
	}
	std::cout << answer;
}
