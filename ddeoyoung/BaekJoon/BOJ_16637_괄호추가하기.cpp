// 2024.08.28
// BOJ 16637 괄호추가하기
#include <bits/stdc++.h>
using namespace std;
int n, res = -987654321;
vector<int> num;
vector<char> oper;
string s;

int cal(char a, int b, int c) {
	if (a == '+') return b + c;
	if (a == '-') return b - c;
	if (a == '*') return b * c;
}

void go(int here, int _num) {
	if (here == num.size() - 1) {
		res = max(res, _num);
		return;
	}
	
	go(here + 1, cal(oper[here], _num, num[here + 1]));
	if (here + 2 <= num.size() - 1) {
		int temp = cal(oper[here + 1], num[here + 1], num[here + 2]);
		go(here + 2, cal(oper[here], _num, temp));
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) num.push_back(s[i] - '0');
		else oper.push_back(s[i]);
	}
	go(0, num[0]);
	cout << res;
	return 0;
}
