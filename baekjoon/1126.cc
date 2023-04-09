#include <bits/stdc++.h>

using namespace std;
vector<int> arr;
const int INF = numeric_limits<int>::max();
int dp[51][250001];
int N;

int solve(int idx, int diff) {
    if(diff > 250000) return -INF;
    if(idx >= N && diff == 0) return 0; 
    if(idx >= N) return -INF;
    int& ret = dp[idx][diff];
    if(ret != -1) return ret;
    ret = -INF;
    ret = max(ret, solve(idx+1, diff));
    ret = max(ret, solve(idx+1, diff + arr[idx]));
    if(diff < arr[idx]) {
        ret = max(ret, solve(idx+1, arr[idx] - diff) + diff);
    }
    else {
        ret = max(ret, solve(idx+1, diff - arr[idx]) + arr[idx]);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    arr.resize(N);
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    int ans = solve(0, 0);
    if(ans == 0) ans = -1;
    cout << ans;
}