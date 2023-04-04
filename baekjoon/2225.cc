#include <bits/stdc++.h>

using namespace std;
const int MOD = 1000000000;
int dp[201][201];
int N, K;

int solve(int cur, int cnt) {
    if(cur == N && cnt == K) return 1;
    if(cnt > K || cur > N) return 0;
    int &ret = dp[cur][cnt];
    if(ret != -1) return ret;
    ret = 0;
    for(int i=N-cur; i>=0; --i) {
        ret += solve(cur + i, cnt + 1);
        ret %= MOD;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0) % MOD;

}