// 2024.08.22
// BOJ 1325 효율적인 해킹
#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, m_cnt, cnt, ret;
vector<int> adj[10001], res;
bool visited[10001];

int dfs(int h) {
	int ret = 1;
	visited[h] = 1;
	for (int t : adj[h]) {
		if (visited[t]) continue; // 사이클 예외처리
		ret += dfs(t);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[b].push_back(a);
	}

	// 탐색
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		if (adj[i].empty()) continue;
		int c_cnt = dfs(i); // 해킹 가능한 컴퓨터 수 DFS

		if (c_cnt == m_cnt) res.push_back(i);
		else if (c_cnt > m_cnt) {
			res.clear();
			m_cnt = c_cnt;
			res.push_back(i);
		}
	}

	// 출력
	sort(res.begin(), res.end());
	for (int i : res) cout << i << " ";
	return 0;
}
