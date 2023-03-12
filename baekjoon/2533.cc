#include <bits/stdc++.h>

using namespace std;
int N;
vector<vector<int>> edges;
int dp[1000000][2];

int dfs(int cur, int post) {
    dp[cur][1] = 1;
    for(int i=0; i<edges[cur].size(); i++) {
        if(edges[cur][i] == post) continue;
        dfs(edges[cur][i], cur);
        dp[cur][1] += min(dp[edges[cur][i]][0], dp[edges[cur][i]][1]);
        dp[cur][0] += dp[edges[cur][i]][1];
    }
    return min(dp[cur][0], dp[cur][1]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    edges.resize(N+1);
    for(int i=0; i<N-1; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    cout << dfs(1, 0);
}