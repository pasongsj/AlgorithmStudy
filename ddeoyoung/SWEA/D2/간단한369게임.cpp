// 2024.11.13
// SWEA_1926_간단한369게임

#include <bits/stdc++.h>
using namespace std;

int N;

int main(int argc, char** argv)
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		string s = to_string(i);
		int cnt = 0;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '3' || s[j] == '6' || s[j] == '9') cnt++;
		}
		if (cnt == 0) cout << s << " ";
		else {
			for (int j = 0; j < cnt; j++) cout << "-";
			cout << " ";
		}
	}
	
	return 0;
}
