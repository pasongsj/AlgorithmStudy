//2024.08.27
// BOJ 4179 불!
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pp;
const int INF = 987654321;
int r, c, res, y, x, sy, sx;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int j[1001][1001], f[1001][1001];
char a[1001][1001];

bool in(int a, int b) {
	return (0 <= a && a < r && 0 <= b && b < c);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	queue<pp> q;
	cin >> r >> c;
	fill(&f[0][0], &f[0][0] + 1001 * 1001, INF); // 초기화
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'F') {
				f[i][j] = 1; 
				q.push({ i, j }); // 불 좌표 저장
			}
			else if (a[i][j] == 'J') {
				sy = i; sx = j;
			}
		}
	}

	// 불의 최단거리와 지훈의 최단거리 비교
	// 불 최단거리
	while (q.size()) {
		tie(y, x) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!in(ny, nx)) continue;
			if (f[ny][nx] != INF || a[ny][nx] == '#') continue;
			f[ny][nx] = f[y][x] + 1; // cnt
			q.push({ ny, nx });
		}
	}


	// 지훈 최단거리
	j[sy][sx] = 1;
	q.push({ sy, sx });
	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (x == c - 1 || y == r - 1 || x == 0 || y == 0) {
			res = j[y][x];
			break; // 탈출
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!in(ny, nx)) continue;
			if (j[ny][nx] || a[ny][nx] == '#') continue;
			if (f[ny][nx] <= j[y][x] + 1) continue;
			j[ny][nx] = j[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	if (res != 0) cout << res << "\n";
	else cout << "IMPOSSIBLE\n";
	return 0;
}
