#include <bits/stdc++.h>

using namespace std;
int N;
vector<int> people;
vector<vector<int>> edges;
int visited[10001];
int dp[10001][2];

void dfs(int x) {
    visited[x] = 1;
    dp[x][0] = 0;
    dp[x][1] = people[x-1];
    for(int i : edges[x]) {
        if(visited[i]) continue;
        dfs(i);
        dp[x][0] += max(dp[i][0], dp[i][1]);
        dp[x][1] += dp[i][0];
    }
}   

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    edges.resize(N+1);
    for(int i=0; i<N; i++) {
        int temp; cin >> temp;
        people.push_back(temp);
    }
    for(int i=0; i<N-1; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for(int i=0; i<N+1; i++) {
        visited[i] = 0;
        for(int j=0; j<2; j++) dp[i][j] = 0;
    }
    dfs(1);
    cout << max(dp[1][0], dp[1][1]);
}