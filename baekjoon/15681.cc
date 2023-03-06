#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> edges;
int visited[100001];
int dp[100001];

int dfs(int x) {
    if(visited[x]) return dp[x];
    visited[x] = 1;
    int res = 1;
    for(int i : edges[x]) {
        if(visited[i]) continue;
        res += dfs(i);
    }
    return dp[x] = res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, R, Q;
    cin >> N >> R >> Q;
    edges.resize(N+1);
    for(int i=1; i<N; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for(int i=1; i<N+1; i++) {
        dp[i] = 0; visited[i] = 0;
    }
    dfs(R);
    for(int i=0; i<Q; i++) {
        int temp; cin >> temp;
        cout << dp[temp] << "\n";
    }
}