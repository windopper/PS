#include <bits/stdc++.h>

using namespace std;
const int MOD = 10007;
int n;
int dp[1001];

int dfs(int k) {
    if(k<=1) return 1;
    int &ret = dp[k];
    if(ret != -1) return ret;
    ret = (dfs(k-1) + dfs(k-2)) % MOD;
    return ret;
}

int solve(int k) {
    if(k % 2 == 1) {
        return (dfs(k) - dfs(k/2) + MOD) % MOD;
    }
    int ret = dfs(k);
    ret = (ret - dfs(k/2) + MOD) % MOD;
    ret = (ret - dfs(k/2-1) + MOD) % MOD;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    memset(dp, -1, 1001);
    dp[0] = 0;
    dp[1] = 1;
    cout << dfs(n);
}