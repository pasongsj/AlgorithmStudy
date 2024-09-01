// 2024.09.01
// BOJ 14497 주난의 난
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pp;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int n, m, cnt, x, y, nx, ny;
char a[301][301];
int visited[301][301];
string s;
queue<pp> q;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int x1, y1, x2, y2;
	cin >> n >> m >> y1 >> x1 >> y2 >> x2;
	y1--; x1--; y2--; x2--;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j];
		}
	}

	q.push({ y1, x1 });
	visited[y1][x1] = 1;
	while (a[y2][x2] != '0') {
		cnt++;
		queue<pp> temp;
		while (q.size()) {
			y = q.front().first;
			x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
				visited[ny][nx] = cnt;
				if (a[ny][nx] != '0') {
					a[ny][nx] = '0';
					temp.push({ ny, nx }); // 1인 좌표들만 저장 = 다음 탐색할 정점들
				}
				else q.push({ ny, nx }); // 0인 좌표들
			}
		}
		q = temp; // 바꾸기
	}

	cout << visited[y2][x2];
	return 0;
}
