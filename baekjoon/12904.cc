#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    while(s2.size() != s1.size()) {
        if(s2[s2.length() - 1] == 'A') {
            s2.pop_back();
        }
        else {
            s2.pop_back();
            reverse(s2.begin(), s2.end());
        }
    }
    if(s2 == s1) {
        cout << 1;
    }
    else cout << 0;
}