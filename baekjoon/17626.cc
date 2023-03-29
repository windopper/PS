#include <bits/stdc++.h>

using namespace std;
int n;
int dp[50001];

int solve(int cur) {
    if(cur == 0) return 0;
    int &ret = dp[cur];
    if(ret != -1) return ret;
    ret = 50001;
    for(int i = floor(sqrt(cur)); i>=1; --i) {
        if(cur - i < 0) continue;
        ret = min(ret, solve(cur - i*i) + 1);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    cout << solve(n);
}