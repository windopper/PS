#include <bits/stdc++.h>

using namespace std;
const int INF = 987654321;

int dp[1000001];

int solve(int cur) {
    if(cur == 1) return 0;
    int &ret = dp[cur];
    if(ret != -1) return ret;
    ret = INF;

    if(cur % 3 == 0) {
        ret = min(ret, solve(cur / 3) + 1);
    }
    if(cur % 2 == 0) {
        ret = min(ret, solve(cur / 2) + 1);
    }
    ret = min(ret, solve(cur - 1) + 1);

    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    cout << solve(N);
}