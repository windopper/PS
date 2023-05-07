#include <bits/stdc++.h>

using namespace std;
const int MOD = 1000000;
int dp[1500000];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = dp[2] = 1;
    for(int i=2; i<1500000; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }
    long long N;
    cin >> N;
    cout << dp[N % 1500000];
}