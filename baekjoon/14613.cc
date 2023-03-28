#include <bits/stdc++.h>

using namespace std;
double W, L, D;
double dp[4001][22];

double solve(int cur, int remain) {
    if(cur >= 1000 && cur <= 1500 && remain == 0) return 1;
    if(remain == 0) return 0;
    double ret = dp[cur][remain];
    if(ret != -1) return ret;
    ret = 0;
    ret = W * solve(cur + 50, remain - 1) + L * solve(cur - 50, remain - 1) + D * solve(cur, remain - 1);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> W >> L >> D;
    memset(dp, -1, sizeof(dp));
    cout << solve(2000, 20);
}