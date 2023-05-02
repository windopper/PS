#include <bits/stdc++.h>

using namespace std;
vector<int> arr;
int N;
int dp[130000][31];

int solve(int cur, int t) {
    if(t == 16000) return 1;
    if(cur >= N) return 0;
    int &ret = dp[t][cur];
    if(ret != -1) return ret;
    ret = 0;
    ret = max(ret, solve(cur + 1, t + arr[cur]));
    ret = max(ret, solve(cur + 1, t - arr[cur]));
    ret = max(ret, solve(cur + 1, t));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<N; i++) {
        int t; cin >> t;
        arr.push_back(t);
    }
    int M;
    cin >> M;
    for(int i=0; i<M; i++) {
        int t; cin >> t;
        if(solve(0, t + 16000)) cout << 'Y';
        else cout << 'N';
        cout << " ";
    }
}