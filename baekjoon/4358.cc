#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed, cout.precision(4);
    int cnt = 0;
    string s;
    map<string, int> m;
    set<string> st;
    while(getline(cin, s)) {
        st.insert(s);
        ++m[s];
        ++cnt;
    }

    for(string s : st) {
        cout << s << " " << (round(((double)m[s] / cnt) * 1000000) / 10000) << "\n";
    }
}