#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string S;
    while(1) {
        cin >> S;
        if(S == ".") break;

        int ans = 0;
        vector<int> pi(S.size(), 0);
        int begin = 1, matched = 0;
        while(begin + matched < S.size()) {
            if(S[begin + matched] == S[matched]) {
                ++matched;
                pi[begin+matched-1] = matched;
                ans = max(ans, matched);
            }
            else {
                if(matched == 0) ++begin;
                else {
                    begin += matched - pi[begin+matched-1];
                    matched = pi[begin+matched-1];
                }
            }
        }

        if(ans == 0) ans = 1;

        cout << ans << '\n';
    }
}