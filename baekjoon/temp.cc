#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
map<string, bool> mp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string S, E, Q;
    cin >> S >> E >> Q;
    int timeS = stoi(S.substr(0, 2)) * 60 + stoi(S.substr(3, 2));
    int timeE = stoi(E.substr(0, 2)) * 60 + stoi(E.substr(3, 2));
    int timeQ = stoi(Q.substr(0, 2)) * 60 + stoi(Q.substr(3, 2));
    string a, b;
    int ans = 0;
    while(cin >> a >> b) {
        int timeA = stoi(a.substr(0, 2)) * 60 + stoi(a.substr(3, 2));
        if(timeA <= timeS) {
            mp[b] = true;
        }
        else if(timeE <= timeA && timeA <= timeQ) {
            if(mp[b]) ++ans;
            mp[b] = false;
        }
    }

    cout << ans;
}