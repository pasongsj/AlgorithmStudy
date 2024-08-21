// 2024.08.21
#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, t, ny, nx, a[101][101], b[101][101];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
bool visited[101][101], visited2[101][101];

void dfs(int y, int x) {
	visited[y][x] = 1;
	b[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (a[ny][nx] == 0 && !visited[ny][nx]) {
			dfs(ny, nx);
		}
	}
	return;
}

void dfs2(int y, int x) {
	visited2[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (b[ny][nx] == 1 && b[y][x] == 0) {
			b[y][x] = 2;
			a[y][x] = 0;
			cnt++;
			continue;
		}
		if (b[ny][nx] == 0 && !visited2[ny][nx]) { // 다음 탐색
			dfs2(ny, nx);
		}
	}
	return;
}

bool check_cheese() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1) return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	while (true) {
		if (check_cheese()) {
			// 1. 치즈 구멍 찾기
			dfs(0, 0);
			cnt = 0;

			// 2. 맞닿는 부분 제거
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (b[i][j] == 0 && !visited2[i][j]) {
						dfs2(i, j);
					}
				}
			}

			t++;

			// 초기화
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					b[i][j] = 0;
					visited[i][j] = 0;
					visited2[i][j] = 0;
				}
			}
		}
		else {
			break;
		}
	}

	cout << t << "\n" << cnt << "\n";
}
