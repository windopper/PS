#include <bits/stdc++.h>

using namespace std;
const long long MOD = 1000000007;
long long dp[4000001];
int dpEnd = 1;

long long solve(long long val, long long power) {
    if(power == 0) return 1;
    if(power % 2 == 1) {
        return val * solve(val, power - 1) % MOD;
    }
    else {
        long long h = solve(val, power / 2);
        return h * h % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int M;
    cin >> M;
    for(int i=0; i<4000002; i++) {
        dp[i] = 1;
    }
    for(int i=0 ; i<M; i++) {
        int N, K;
        cin >> N >> K;
        int temp = dpEnd;
        for(int i=temp; i<=N; i++) {
            dp[i] = (dp[i-1] * i) % MOD;
            dpEnd = i;
        }
        long long ans = dp[N];
        ans = (ans * solve(dp[K], MOD-2)) % MOD;
        ans = (ans * solve(dp[N-K], MOD-2)) % MOD;
        cout << ans << '\n';
    }
}