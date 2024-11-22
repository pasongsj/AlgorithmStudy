// 2024.11.22
// BOJ_11053_가장긴바이토닉부분수열
#include <bits/stdc++.h>
using namespace std;

int N, n, a[1001], dp[1001], dp2[1001], m, res, m1, m2;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = 0; i < N; i++) {
		int cur = 0;
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j]) {
				if (cur < dp[j]) cur = dp[j];
			}
		}
		dp[i] = cur + 1;
	}

	for (int i = N - 1; i >= 0; i--) {
		int cur = 0;
		for (int j = N - 1; j >= i; j--) {
			if (a[i] > a[j]) {
				if (cur < dp2[j]) cur = dp2[j];
			}
		}
		dp2[i] = cur + 1;
	}

	for (int i = 0; i < N; i++) {
		res = max(res, (dp[i] + dp2[i]));
	}
	cout << res - 1;
	return 0;
}
