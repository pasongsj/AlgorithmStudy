// 2024.08.26
// BOJ 2589 보물섬
#include <bits/stdc++.h>
using namespace std;
int n, m, a[50][50], visited[50][50], res, ny, nx, y, x;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
string s;

int bfs(int sy, int sx) {
	visited[sy][sx] = 1;
	queue<pair<int, int>> q;
	q.push({ sy, sx });
	int cnt = 0;
	while (q.size()) {
		tie(y, x) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (a[ny][nx] == 1 && !visited[ny][nx]) {
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ny, nx});
				cnt = max(cnt, visited[ny][nx]);
			}
		}
	}
	return cnt - 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'W') a[i][j] = 0;
			else if (s[j] == 'L') a[i][j] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1 && !visited[i][j]) {
				int cnt = bfs(i, j);
				res = max(res, cnt);
			}
			memset(visited, 0, sizeof(visited));
		}
	}

	cout << res;
	return 0;
}
