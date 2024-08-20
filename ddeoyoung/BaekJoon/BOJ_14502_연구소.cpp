// 2024.08.20
// BOJ 14502 연구소
#include <bits/stdc++.h>
using namespace std;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int n, m, res, cnt, a[8][8], b[8][8], ny, nx;
bool visited[8][8];

void dfs(int x, int y) {
	visited[x][y] = 1;
	b[x][y] = 2;
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
		if (b[nx][ny] == 0 && !visited[nx][ny]) {
			dfs(nx, ny);
		}
	}
	return;
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
  
	// 3개의 좌표 뽑기
	for (int i = 0; i < n * m; i++) {
		for (int j = i + 1; j < n * m; j++) {
			for (int k = j + 1; k < n * m; k++) {
				int x1 = i / m, y1 = i % m;
				int x2 = j / m, y2 = j % m;
				int x3 = k / m, y3 = k % m;

				// 버퍼 오버런 방지
				if (y1 >= m || y2 >= m || y3 >= m || x1 >= n || x2 >= n || x3 >= n) continue;

				// 벽 세우기
				if (a[x1][y1] == 0 && a[x2][y2] == 0 && a[x3][y3] == 0) {
					a[x1][y1] = 1;
					a[x2][y2] = 1;
					a[x3][y3] = 1;

					// visited, b 배열 초기값 입력
					for (int x = 0; x < n; x++) {
						for (int y = 0; y < m; y++) {
							if (a[x][y] == 1) {
								b[x][y] = 1;
								visited[x][y] = 1;
							}
							else if (a[x][y] == 2) {
								b[x][y] = 2;
								visited[x][y] = 0;
							}
							else {
								b[x][y] = 0;
								visited[x][y] = 0;
							}
						}
					}
					for (int x = 0; x < n; x++) {
						for (int y = 0; y < m; y++) {
							// 바이러스 퍼지기
							if (b[x][y] == 2 && !visited[x][y]) {
								dfs(x, y);
							}
						}
					}
					// 안전구역 세기
					for (int x = 0; x < n; x++) {
						for (int y = 0; y < m; y++) {
							if (b[x][y] == 0) cnt++;
						}
					}
					res = max(res, cnt);
					cnt = 0;
					a[x1][y1] = 0;
					a[x2][y2] = 0;
					a[x3][y3] = 0;

				}
			}
		}
	}
	cout << res << "\n";
}
