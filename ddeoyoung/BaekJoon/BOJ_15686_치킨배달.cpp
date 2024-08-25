// 2024.08.25
// BOJ 15686 치킨 배달
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pp;
int n, m, res, total, a[50][50];
vector<pp> v, ch;

// 각 집마다의 치킨거리 최소값
int cal(int y, int x, vector<pp> ch) {
	int ret = 0;
	for (int i = 0; i < ch.size(); i++) {
		int sum = abs(y - ch[i].first) + abs(x - ch[i].second);
		if (ret == 0) ret = sum;
		else ret = min(ret, sum);
	}
	//cout << y << ", " << x << "의 치킨거리 : " << ret << "\n";
	return ret;
}

int go(vector<pp> ch) {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1) ret += cal(i, j, ch);
		}
	}
	//cout << "이 조합의 도시치킨거리 : " << ret << "\n";
	return ret;
}

void combi(int start, vector<pp> ch) {
	if (ch.size() == m) {
		//cout << "////////치킨집 조합////////\n";
		//for (pp p : ch) cout << p.first << " " << p.second << "\n";
		// 2. 해당 조합의 치킨거리 계산
		total = go(ch);
		if (res == 0) res = total;
		else res = min(res, total);
		ch.clear();
		return;
	}

	// 1. 치킨집 조합 뽑기
	for (int i = start + 1; i < v.size(); i++) {
		ch.push_back(v[i]);
		combi(i, ch);
		ch.pop_back();
	}
	return;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 2) v.push_back({ i, j }); // 치킨집 좌표 저장
		}
	}
	combi(-1, ch);
	cout << res;
	return 0;
}
