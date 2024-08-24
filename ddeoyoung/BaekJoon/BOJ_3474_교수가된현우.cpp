// BOJ 3474 교수가 된 현우
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll n, a, b, cnt1, cnt2, res;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		a = 2;
		cnt1 = 0;
		while (n / a != 0) {
			cnt1 += n / a;
			a *= 2;
		}
		b = 5;
		cnt2 = 0;
		while (n / b != 0) {
			cnt2 += n / b;
			b *= 5;
		}
		res = min(cnt1, cnt2);
		cout << res << "\n";
	}
	return 0;
}
