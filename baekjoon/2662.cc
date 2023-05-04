#include <bits/stdc++.h>

using namespace std;
int N, M;
long long dp[301][21];
int tracedp[301][21];
vector<vector<int>> arr;
vector<int> ans;

long long solve(int remain, int cur) {
    if(remain == 0) {
        return 0;
    }
    if(cur >= M) return 0;
    long long &ret = dp[remain][cur];
    if(ret != -1) return ret;
    ret = 0;
    int val = solve(remain, cur + 1);
    if(ret < val) {
        ret = val;
        tracedp[remain][cur] = 0;
    }
    for(int i=1; i<=N; i++) {
        if(i > remain) break;
        val = solve(remain - i, cur + 1) + arr[i][cur];
        if(ret < val) {
            ret = val;
            tracedp[remain][cur] = i;
        }
    }
    return ret;
}

void track(int remain, int cur) {
    if(cur == M) return;
    cout << tracedp[remain][cur] << " ";
    track(remain - tracedp[remain][cur], cur + 1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    memset(dp, -1, sizeof(dp));
    arr.resize(N+1);
    for(int i=0; i<N; i++) {
        int cost;
        cin >> cost;
        for(int j=0; j<M; j++) {
            int ret;
            cin >> ret;
            arr[cost].push_back(ret);
        }
    }
    cout << solve(N, 0) << '\n';
    track(N, 0);
    for(int cur : ans) cout << cur << " ";
}