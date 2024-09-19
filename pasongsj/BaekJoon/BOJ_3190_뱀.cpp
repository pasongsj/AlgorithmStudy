#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> arr;
std::vector<std::pair<int, char>> dirchange;
std::queue<std::pair<int, int>> trail;
int n;
int answer;
int dirindex;

bool InRange(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < n;
}

void DFS(std::pair<int, int> head, int dir, int cnt)
{
	const int dx[4] = { 0, 1, 0, -1 };
	const int dy[4] = { 1, 0, -1,0 };

	answer = answer > cnt ? answer : cnt;
	if (dirindex <dirchange.size() && dirchange[dirindex].first == cnt)
	{
		if (dirchange[dirindex].second == 'D')
		{
			dir = (dir + 1) % 4;
		}
		else
		{
			dir = (dir + 3) % 4;
		}
		dirindex++;
	}

	int nx = head.first + dx[dir];
	int ny = head.second + dy[dir];

	if (false == InRange(nx, ny) || -1 == arr[nx][ny])
	{
		return;
	}
	else if (0 == arr[nx][ny])
	{
		std::pair<int, int> tail = trail.front();
		trail.pop();
		arr[tail.first][tail.second] = 0;
		trail.push(std::make_pair(nx, ny));
		arr[nx][ny] = -1;
		DFS(std::make_pair(nx, ny), dir, cnt + 1);
	}
	else if (1 == arr[nx][ny])
	{
		trail.push(std::make_pair(nx, ny));
		arr[nx][ny] = -1;
		DFS(std::make_pair(nx, ny), dir, cnt + 1);
	}
}

int main()
{

	std::cin >> n;
	arr.resize(n);
	for (int i = 0;i < n;++i)
	{
		arr[i].resize(n);
	}

	int ap;
	std::cin >> ap;
	for (int i = 0;i < ap;++i)
	{
		int a, b;
		std::cin >> a >> b;
		arr[--a][--b] = 1;
	}

	int dcnt;
	std::cin >> dcnt;

	for (int i = 0;i < dcnt;++i)
	{
		int x;
		char d;
		std::cin >> x >> d;
		dirchange.push_back(std::make_pair(x, d));
	}

	answer = 0;
	dirindex = 0;
	trail.push(std::make_pair(0, 0));
	DFS(std::make_pair(0, 0), 0, 0);
	std::cout << answer+1;

	return 0;

}
