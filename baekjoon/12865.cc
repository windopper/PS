#include <bits/stdc++.h>

using namespace std;
int dp[101][100001];
vector<pair<int, int>> wv;
int N, K;

int solve(int c, int w) {
    if(c == N) return 0; // 기저

    int &ret = dp[c][w];
    if(ret != -1) return ret;

    int weight = wv[c].first;
    int value = wv[c].second;

    if(w + weight <= K) {
        ret = max(ret, solve(c+1, w + weight) + value);
    }
    ret = max(ret, solve(c+1, w));

    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for(int i=0; i<N; i++) {
        int W, V;
        cin >> W >> V;
        wv.push_back({W, V});
    }
    solve(0, 0);
}