#include <bits/stdc++.h>
using namespace std;
int n, k, v;
string s;
unordered_map<int, int> m;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(s == "add"){
            cin >> k >> v;
            m[k] = v;
        }
        else if (s == "find"){
            cin >> k;
            if(m.find(k) != m.end()) cout << m[k] << "\n";
            else cout << "None\n";
        }
        else if (s == "remove"){
            cin >> k;
            m.erase(k);
        }
    }
    return 0;
}
