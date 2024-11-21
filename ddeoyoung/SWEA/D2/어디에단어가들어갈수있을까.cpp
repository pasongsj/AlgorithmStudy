// 2024.11.14
// SWEA_1979_어디에단어가들어갈수있을까

#include <bits/stdc++.h>

using namespace std;

int test_case, T, N, K, res;
int a[17][17];

int main(int argc, char** argv)
{
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> K;
		memset(a, 0, 17);
		res = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> a[i][j];
			}
		}

		// 가로
		for (int i = 0; i < N; i++) {
			int j = 0;
			int cnt = 0;
			while (true) {
				if (a[i][j] == 0) {
					if (cnt == K) res++;
					cnt = 0;
					j++;
				}
				else if (a[i][j] == 1) {
					cnt++;
					j++;
				}
				if (j == N) {
					if (cnt == K) res++;
					break;
				}
			}
		}

		// 세로
		for (int j = 0; j < N; j++) {
			int i = 0;
			int cnt = 0;
			while (true) {
				if (a[i][j] == 0) {
					if (cnt == K) res++;
					cnt = 0;
					i++;
				}
				else if (a[i][j] == 1) {
					cnt++;
					i++;
				}
				if (i == N) {
					if (cnt == K) res++;
					break;
				}
			}
		}

		cout << "#" << test_case << " ";
		cout << res << "\n";
	}
	return 0;
}
