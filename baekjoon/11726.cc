#include <bits/stdc++.h>

using namespace std;
const int MOD = 10007;
int n;
int dp[1001];

int solve(int i) {
    if(i >= 0 && i <= 2) {
        return i;
    }
    int &ret = dp[i];
    if (ret != -1) return ret;
    ret = 0;
    ret += solve(i-1);
    ret %= MOD;
    ret += solve(i-2);
    ret %= MOD;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << solve(n);
}