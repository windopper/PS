#include <bits/stdc++.h>

using namespace std;
int N;
int arr[1001];
int dp[1001];

int solve(int cur) {
    if(cur == N) return 0;
    int &ret = dp[cur];
    if(ret != -1) return ret;
    ret = 10001;
    for(int i=1; i<=arr[cur]; i++) {
        if(cur + i > N) continue;
        ret = min(ret, solve(cur + i) + 1);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=1; i<N+1; i++) {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    int ans = solve(1);
    if(ans == 10001) cout << -1;
    else cout << ans;
}