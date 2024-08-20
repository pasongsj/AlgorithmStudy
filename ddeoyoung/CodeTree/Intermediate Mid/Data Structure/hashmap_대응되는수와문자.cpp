// 2024.08.21
#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> mp;
int n, m;
string s, a[100001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> s;
        mp[s] = i;
        a[i] = s;
    }
    for(int i = 0; i < m; i++){ // 숫자
        cin >> s;
        if(atoi(s.c_str())){
            int num = stoi(s);
            cout << a[num] << "\n";
        }
        else { // 문자
            if(mp.find(s) != mp.end()) cout << mp[s] << "\n";
        }
    }
    return 0;
}
