#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string T, P;
    getline(cin, T);
    getline(cin, P);

    // pi 값을 구해둔다.
    vector<int> pi(P.size(), 0);
    int begin = 1, matched = 0;
    while(begin + matched < P.size()) {
        if(P[begin+matched] == P[matched]) {
            ++matched;
            pi[begin+matched-1] = matched;
        }
        else {
            if(matched == 0) ++begin;
            else {
                begin += (matched - pi[matched-1]);
                matched = pi[matched-1];
            }
        }
    }

    begin = 0; matched = 0;
    vector<int> result;
    while(begin + P.size() <= T.size()) {
        if(matched < P.size() && T[begin+matched] == P[matched]) {
            ++matched;
            if(matched == P.size()) result.push_back(begin+1);
        }
        else {
            if(matched == 0) ++begin;
            else {
                begin += (matched - pi[matched-1]);
                matched = pi[matched-1];
            }
        }
    }

    cout << result.size() << "\n";
    for(int cur : result) {
        cout << cur << " ";
    }
}