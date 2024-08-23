// 2024.08.23
// BOJ 17298 오큰수
#include <bits/stdc++.h>
using namespace std;
int n, a, nge, res[1000001];
stack<pair<int, int>> s;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (s.empty()) s.push({i, a});
		else {
			if (s.top().second >= a) s.push({ i, a });
			else if (s.top().second < a) {
				while (s.top().second < a) {
					res[s.top().first] = a;
					s.pop();
					if (s.empty()) break;
				}
				s.push({i, a});
			}
		}
	}
	if (!s.empty()) {
		while (!s.empty()) {
			res[s.top().first] = -1;
			s.pop();
		}
	}
	for (int i = 0; i < n; i++) cout << res[i] << " ";
	return 0;
}
