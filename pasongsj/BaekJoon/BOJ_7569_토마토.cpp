#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

bool InRange(int a, int b, int c, int x, int y, int z)
{
    return 0 <= a && a < x && 0 <= b && b < y && 0 <= c && c < z;
}

int main()
{
    int n, m, h;
    std::cin >> m >> n >> h;
    std::vector<std::vector<std::vector<int>>> box;
	std::queue<std::tuple<int, int, int, int>> q;

    int remaincnt = 0;
    box.resize(h);
    for (int k = 0;k < h;k++)
    {
        box[k].resize(n);
        for (int i = 0;i < n;++i)
        {
            box[k][i].resize(m);
            for (int j = 0;j < m;++j)
            {
                std::cin >> box[k][i][j];
         
                if (0 == box[k][i][j])
                {
                    remaincnt++;
                }
                else if(1 == box[k][i][j])
                {
                    q.push(std::make_tuple(i, j, k, 0));
                }
            }
        }
    }


	const int dx[6] = { 0,0,0,0,1,-1 };
	const int dy[6] = { 0,0,1,-1,0,0 };
	const int dz[6] = { 1,-1,0,0,0,0 };

    int answer = 0;
    while (!q.empty())
    {
		int x, y, z, cnt;
		std::tie(x, y, z, cnt) = q.front();
        q.pop();
        answer = answer > cnt ? answer : cnt;
        for (int i = 0;i < 6;++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if (true == InRange(nx, ny, nz, n, m, h) && 0 == box[nz][nx][ny])
            {
                remaincnt--;
                box[nz][nx][ny] = 1;
                q.push(std::make_tuple(nx, ny, nz, cnt + 1));
            }
        }

    }
    if (remaincnt > 0)
    {
        answer = -1;
    }
    std::cout << answer;
    return 0;
    
}
