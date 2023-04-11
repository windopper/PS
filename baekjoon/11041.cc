#include <bits/stdc++.h>

using namespace std;
const long long MOD = 1000000007;

long long solve(long long val, int power) {
    if(power == 0) return 1;
    if(power % 2 == 1) return val * solve(val, power - 1) % MOD;
    else {
        long long h = solve(val, power/2);
        return h * h % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, K;
    cin >> N >> K;
    long long ans = 1;
    for(int i=N; i>=N-K+1; --i) ans = (ans * i) % MOD;
    long long kf = 1;
    for(int i=K; i>=1; --i) kf = (kf * i) % MOD;
    kf = solve(kf, MOD-2);
    cout << ans * kf % MOD;
}