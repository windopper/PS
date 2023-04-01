#include <bits/stdc++.h>

using namespace std;

int find(string s1, string s2) {
    if(s1 == s2) return 1;
    if(s1.size() == s2.size() && s1 != s2) return 0;

    int ret = 0;
    string c = s2;
    if(s2[s2.size()-1] == 'A') {
        s2.pop_back();
        ret = max(ret, find(s1, s2));
    }
    s2 = c;
    if(s2[0] == 'B') {
        reverse(s2.begin(), s2.end());
        s2.pop_back();
        ret = max(ret, find(s1, s2));
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string a, b;
    cin >> a >> b;
    int ans = find(a, b);
    cout << ans;
}