#include <bits/stdc++.h>

using namespace std;
int N, K;
int dp[1001][1001];
const int MOD = 10007;

int solve(int n, int k) {
    if(k == 0) return 1;
    if(n == k) return 1;
    int &ret = dp[n][k];
    if(ret != -1) return ret;
    ret = (solve(n-1, k-1) + solve(n-1, k)) % MOD;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    memset(dp, -1, sizeof(dp));
    cout << solve(N, K) % MOD;
}