// 2024.08.22
// BOJ 1068 트리
#include <bits/stdc++.h>
using namespace std;
int n, pn, m, res, rn, b[51];
vector<int> a[51];

void go(int rn) {
	b[rn]--;
	if (a[rn].empty() || b[rn] < 0) return;
	for (int i = 0; i < a[rn].size(); i++) {
		b[rn]--;
		int nn = a[rn][i];
		go(nn);
	}
	return;
}

int main() {
	cin >> n;

	// 1. 트리 저장 
	for (int i = 0; i < n; i++) {
		cin >> pn;
		if (pn == -1) continue;
		a[pn].push_back(i);
		b[pn]++; // 개수 저장 배열
	}

	// 2. 삭제될 노드의 부모 노드 찾기 
	cin >> rn;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a[i].size(); j++) {
			if (a[i][j] == rn) b[i]--; // 부모에서 rn 삭제
		}
	}

	// 3. 삭제될 노드의 자식 노드 제거
	go(rn);

	for (int i = 0; i < n; i++) {
		if (b[i] == 0) res++;
	}
	cout << res;

	return 0;
}
