#include <bits/stdc++.h>

using namespace std;
int N, S;
vector<pair<int, int>> arr;
vector<int> heights;
int dp[300001];
int maxHeight = 0;
int solve(int cur) {
    if(cur == N) return 0;
    int &ret = dp[cur];
    if(ret != -1) return ret;
    int nxt = lower_bound(heights.begin(), heights.end(), arr[cur].first + S) - heights.begin();
    ret = solve(nxt) + arr[cur].second;
    ret = max(ret, solve(cur + 1));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> S;
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<N; i++) {
        int H, C;
        cin >> H >> C;
        heights.push_back(H);
        arr.push_back({H, C});
    }
    sort(heights.begin(), heights.end());
    sort(arr.begin(), arr.end());
    cout << solve(0);
}