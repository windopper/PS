#include <bits/stdc++.h>

using namespace std;
string s, c;
bool solve(int i, int j) {
    while(i < s.size() && j < c.size() && s[i] == c[j]) {
        ++i;
        ++j;
    }

    if(s.size() == i && c.size() == j) return true;
    if(s[i] == '*') {
        for(int k=j; k<c.size(); k++) {
            if(solve(i+1, k)) return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N >> s;
    for(int i=0; i<N; i++) {
        cin >> c;
        if(solve(0, 0)) {
            cout << "DA";
        }
        else cout << "NE";
        cout << "\n";
    }
}