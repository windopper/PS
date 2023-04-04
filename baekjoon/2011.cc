#include <bits/stdc++.h>

using namespace std;
string N;
int dp[5001];
const int MOD = 1000000;

int solve(int k) {
    cout << k << " ";
    if(k >= N.size()) return 1;
    int &ret = dp[k];
    if(ret != -1) return ret;
    ret = 0;
    for(int i=k; i<N.size(); i++) {
        if(N[i] != '0') ret += solve(i+1) % MOD;
        if(i + 1 < N.size() && stoi(N.substr(i, 2)) < 27) {
            ret += solve(i+2) % MOD;
        }
    }
    return ret % MOD;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    memset(dp, -1, sizeof(dp));
    cout << solve(0);
}