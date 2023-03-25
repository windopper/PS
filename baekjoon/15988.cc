#include <bits/stdc++.h>

using namespace std;
int n;
long long dp[1000001];
const int MOD = 1000000009;

long long solve(int cur) {
    if(cur < 0) return 0;
    if(cur == 0) return 1;
    long long &ret = dp[cur];
    if(ret != -1) return ret;
    ret = (solve(cur - 1) + solve(cur - 2) + solve(cur - 3)) % MOD;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for(; T>0; --T) {
        cin >> n;
        memset(dp, -1, sizeof(dp));
        cout << solve(n) << "\n";
    }
}