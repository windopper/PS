#include <bits/stdc++.h>

using namespace std;
int N;
int dp[100001][3];
const int MOD = 9901;

int solve(int cur, int post) {
    if(cur >= N) return 1;
    int &ret = dp[cur][post];
    if(ret != -1) return ret;
    ret = 0;
    if(post == 0) {
        ret += solve(cur+1, 1);
        ret %= MOD;
        ret += solve(cur+1, 2);
        ret %= MOD;
        ret += solve(cur+1, 0);
        ret %= MOD;
    }
    else if(post == 1) {
        ret += solve(cur+1, 2);
        ret %= MOD;
        ret += solve(cur+1, 0);
        ret %= MOD;
    }
    else if(post == 2) {
        ret += solve(cur+1, 1);
        ret %= MOD;
        ret += solve(cur+1, 0);
        ret %= MOD;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0);
}
