#include <bits/stdc++.h>

using namespace std;
int n;
const int MOD = 1000000009;
int dp[100001];

int solve(int cur, int post) {

    if((cur - post) * 2 + post == n) return 1;
    if((cur - post) * 2 + post > n) return 0;
    if(cur * 2 == n) return 1;
    if(cur * 2 > n) return 0;

    int &ret = dp[cur];
    if(ret != -1) return ret;

    ret = solve(cur + 1, 1);
    ret %= MOD;
    ret += solve(cur + 2, 2);
    ret %= MOD;
    ret += solve(cur + 3, 3);
    ret %= MOD;

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for(; T>0; --T) {
        cin >> n;
        memset(dp, -1, sizeof(dp));
        cout << solve(0, 1) % MOD << "\n";
    }
}