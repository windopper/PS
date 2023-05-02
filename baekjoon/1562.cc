#include <bits/stdc++.h>

using namespace std;
int N;
const long long MOD = 1000000000;
long long dp[101][10][2048];

int popcount(int n) {
    int ret = 0;
    for(; n ; n &= n-1) ret++;
    return ret;
}

long long solve(int len, int post, int vis) {
    if(len == N && popcount(vis) == 10) return 1;
    if(len >= N) return 0;
    long long &ret = dp[len][post][vis];
    if(ret != -1) return ret;
    ret = 0;
    if(post - 1 >= 0) {
        ret += solve(len+1, post - 1, vis | (1 << (post - 1)));
        ret %= MOD;
    }
    if(post + 1 <= 9) {
        ret += solve(len+1, post + 1, vis | (1 << (post + 1)));
        ret %= MOD;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    memset(dp, -1, sizeof(dp));
    long long ans = 0;
    for(int i=1; i<=9; i++) {
        ans += solve(1, i, 1 << i);
        ans %= MOD;
    }
    cout << ans;
}