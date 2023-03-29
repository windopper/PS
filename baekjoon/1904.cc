#include <bits/stdc++.h>

using namespace std;
int N;
int dp[1000001];
const int MOD = 15746;

int solve(int cur) {
    if(cur == 0) return 1;
    if(cur < 0) return 0;
    int &ret = dp[cur];
    if(ret != -1) return ret;
    ret = 0;
    ret = (solve(cur- 1) + solve(cur - 2)) % MOD;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    memset(dp, -1, sizeof(dp));
    cout << solve(N);
}