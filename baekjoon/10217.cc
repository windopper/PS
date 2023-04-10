#include <bits/stdc++.h>

using namespace std;
int N, M, K;
vector<vector<vector<int>>> adj;
int dp[101][100001];

int solve(int cur, int c) {
    if(cur == N) return 0;
    int& ret = dp[cur][c];
    if(ret != -1) return ret;
    ret = 987654321;
    for(vector<int> next : adj[cur]) {
        if(c + next[1] <= M) 
            ret = min(ret, solve(next[0], c + next[1]) + next[2]);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for(; T>0; --T) {
        cin >> N >> M >> K;
        adj.assign(N+1, vector<vector<int>>());
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<K; i++) {
            int u, v, c, d;
            cin >> u >> v >> c >> d;
            adj[u].push_back({v, c, d});
        }       
        int ans = solve(1, 0);
        if(ans == 987654321) {
            cout << "Poor KCM";
        }
        else cout << ans;
        cout << '\n';
    }
}