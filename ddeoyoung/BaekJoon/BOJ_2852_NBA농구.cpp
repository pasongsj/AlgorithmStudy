// BOJ 2852 NBA농구
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pp;
int T, n, cnt1, cnt2, cur_n, s1, s2;
string t, m, s;
pp p[104];
int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n >> t;
		p[i] = { n, stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3))};
		if (i == T - 1) p[i + 1] = { 0, 2880 };
	}
	for (int i = 0; i <= T; i++) {
		cur_n = p[i].first;
		if (i > 0) {
			if (s1 > s2) cnt1 += p[i].second - p[i - 1].second;
			else if (s1 < s2) cnt2 += p[i].second - p[i - 1].second;
		}

		// 득점 체크
		if (cur_n == 1) s1++;
		else if (cur_n == 2) s2++;
	}

	m = "00" + to_string(cnt1 / 60);
	s = "00" + to_string(cnt1 % 60);
	cout << m.substr(m.size() - 2, 2) + ":" + s.substr(s.size() - 2, 2) << "\n";

	m = "00" + to_string(cnt2 / 60);
	s = "00" + to_string(cnt2 % 60);
	cout << m.substr(m.size() - 2, 2) + ":" + s.substr(s.size() - 2, 2) << "\n";
	return 0;
}
