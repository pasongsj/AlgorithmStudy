// 2024.11.21
// BOJ_11053_가장긴증가하는부분수열
#include <bits/stdc++.h>
using namespace std;

int N, n, dp[1001], res;
vector<int> v;

int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> n;
		v.push_back(n);
		int cur = 0;
		for (int j = 0; j < v.size(); j++) {
			if (v[i] > v[j]) {
				if (cur < dp[j]) cur = dp[j];
			}
		}
		dp[i] = cur + 1;
		res = max(res, dp[i]);
	}

	cout << res;
	return 0;
}
