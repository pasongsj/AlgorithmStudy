// 2024.08.26
// BOJ 16234 인구 이동
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pp;
int n, L, R, res, ny, nx, sum, cnt, temp;
int a[50][50];
bool visited[50][50];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
vector<pp> v;

void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
		int diff = abs(a[y][x] - a[ny][nx]);
		if (diff >= L && diff <= R) {
			v.push_back({ ny, nx }); // 연합국가 인구 수 : b에 저장
			sum += a[ny][nx];
			dfs(ny, nx);
		}
	}
	return;
}

int main() {
	cin >> n >> L >> R;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	while (true) {
		memset(visited, 0, sizeof(visited));
		bool flag = 0;

		// 1. 연합국가 탐색
		// 모든 국가의 국경을 열어 탐색을 한 후, 닫는다
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) { // 연결된 컴포넌트 시작
					v.clear();
					v.push_back({ i, j });
					sum = a[i][j];
					dfs(i, j);
					if (v.size() == 1) continue; // 연결 컴포넌트 없음
					for (pp p : v) { // 2. 인구 이동
						a[p.first][p.second] = sum / v.size();
						flag = 1;
					}
				}
			}
		}
		if (flag == 0) break; // 반복문 종료
		res++;
	}
	cout << res;
	return 0;
}
