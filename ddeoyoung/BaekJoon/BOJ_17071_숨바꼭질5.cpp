// 2024.08.31
// BOJ 17071 숨바꼭질5
#include <bits/stdc++.h>
using namespace std;
const int max_n = 500000;
int n, k, x, nx, t = 1, visited[2][max_n + 4], check;

int cal(int i, int x) {
	if (i == 0) return x + 1;
	else if (i == 1) return x - 1;
	else if (i == 2) return x * 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	if (n == k) { cout << 0 << "\n"; return 0; }
	queue<int> q;
	q.push(n);
	visited[0][n] = 1; // 수빈이의 방문 체크
	while (q.size()) {
		k += t; // 시간
		if (k > max_n) break;
		if (visited[t % 2][k]) { // 홀짝 체크
			check = 1; // 수빈이와 동생 만남
			break;
		}
		int qSize = q.size(); // 플러드필 (턴 분리)
		for (int i = 0; i < qSize; i++) {
			x = q.front(); 
			q.pop();
			for (int j = 0; j < 3; j++) {
				nx = cal(j, x);
				if (nx < 0 || nx > max_n || visited[t % 2][nx]) continue;
				visited[t % 2][nx] = visited[(t + 1) % 2][x] + 1;
				if (nx == k) { check = 1; break; }
				q.push(nx);
			}
			if (check) break;
		}
		if (check) break;
		t++;
	}
	if (check) cout << t << "\n";
	else cout << -1 << "\n";
	return 0;
}
