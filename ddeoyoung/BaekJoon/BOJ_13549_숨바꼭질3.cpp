// 2024.08.31
// BOJ 13549 숨바꼭질3
#include <bits/stdc++.h>
using namespace std;
const int max_n = 100001;
int n, k, x, nx, t, a[max_n];

int cal(int i, int x) {
	if (i == 0) return x * 2;
	else if (i == 1) return x - 1;
	else if (i == 2) return x + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	queue<int> q;
	q.push(n);
	a[n] = 1;
	while (q.size()) {
		x = q.front(); q.pop();
		if (x == k) { cout << a[x] - 1; break; }
		for (int i = 0; i < 3; i++) {
			bool check = true;
			if (i > 0) check = false;
			nx = cal(i, x);
			if (nx < 0 || nx > max_n - 1 || a[nx]) continue;
			if (check) a[nx] = a[x];
			else a[nx] = a[x] + 1;
			q.push(nx);
		}
	}
	return 0;
}

// BFS : 가중치가 같은 그래프에서의 최단거리 알고리즘
// 이 문제에서는 가중치가 같지 않기 때문에 (2*x => 0초, x+1 x-1 => 1초)
// 가중치가 0인 간선이 있는 경우
// 다익스트라, 0-1 BFS 를 사용해야 한다
// 0-1 BFS: 가중치가 0인 간선에 연결된 정점은 큐의 맨 뒤가 아닌 앞에 넣는 방법
// *2를 별도의 간선으로 생각하지 않고 +1이나 -1에 의한 좌표를 큐에 넣을 때
// 그 좌표의 2의 거듭제곱 배인 좌표들을 전부 큐에 넣는 방법
