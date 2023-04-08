#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;

    vector<int> pi(s.size(), 0);
    int ans = 0;
    int begin = 1, matched = 0;
    while(begin + matched < s.size()) {
        if(s[matched] == s[begin + matched]) {
            ++matched;
            pi[begin + matched - 1] = matched;
            ans = max(ans, matched);
        }
        else {
            if(matched == 0) ++begin;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }

    cout << ans;
}