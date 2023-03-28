#include <bits/stdc++.h>

using namespace std;
int n;
int dp[10001][3];

int solve(int cur, int lim) {
    if(cur == n) {
        return 1;
    }
    if(cur > n) return 0;
    int &ret = dp[cur][lim-1];
    if(ret != -1) return ret;
    ret = 0;
    if(lim >= 3) {
        ret += solve(cur + 3, 3);
    }
    if(lim >= 2) {
        ret += solve(cur + 2, 2);
    }
    if(lim >= 1) {
        ret += solve(cur + 1, 1);
    }
    return ret;   
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for(; T>0; --T) {
        cin >> n;
        memset(dp, -1, sizeof(dp));
        cout << solve(0, 3) << "\n";
    }
}