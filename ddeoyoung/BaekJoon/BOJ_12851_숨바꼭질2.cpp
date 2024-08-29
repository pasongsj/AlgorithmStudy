// 2024.08.29
// BOJ 12851 숨바꼭질 2
#include <bits/stdc++.h>
using namespace std;
int res = 987654321;
int n, k, x, nx, cnt[100004], a[100004];

int cal(int i, int x) {
	if (i == 0) return x - 1;
	else if (i == 1) return x + 1;
	else if (i == 2) return x * 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	if (n == k) {
		puts("0"); puts("1");
		return 0;
	}
	queue<int> q;
	q.push(n);
	a[n] = 1;
	cnt[n] = 1;
	while (q.size()) {
		x = q.front();
		q.pop();
		for (int i = 0; i < 3; i++) {
			nx = cal(i, x);
			if (nx < 0 || nx > 100000) continue;
			if (!a[nx]) {
				a[nx] = a[x] + 1;
				cnt[nx] += cnt[x]; // 경우의 수 더하기
				q.push(nx);
			}
			else if (a[nx] == a[x] + 1) cnt[nx] += cnt[x];
		}
	}
	cout << a[k] - 1 << "\n";
	cout << cnt[k] << "\n";
	return 0;
}
