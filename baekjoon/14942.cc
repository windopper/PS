#include <bits/stdc++.h>

using namespace std;
vector<int> energy;
int dp[18][100001];
int dist[18][100001];
int level[100001];
vector<vector<pair<int, int>>> edges;

void dfs(int cur, int post) {
    for(int i=1; i<18; i++) {
        dp[i][cur] = dp[i-1][dp[i-1][cur]];
        dist[i][cur] = dist[i-1][cur] + dist[i-1][dp[i-1][cur]];
    }
    for(int i=0; i<edges[cur].size(); i++) {
        int future = edges[cur][i].first;
        int cost = edges[cur][i].second;
        if(future == post) continue;
        dp[0][future] = cur;
        dist[0][future] = cost;
        level[future] = level[cur] + 1;
        dfs(future, cur);
    }
}

int solve(int x, int en) {

    int totalDist = 0;

    for(int i=17; i>=0; --i) {
        if(dp[i][x] != 0 && totalDist + dist[i][x] <= en) {
            totalDist += dist[i][x];
            x = dp[i][x];
        }
    }
    
    return x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    energy.resize(n);
    for(int i=0; i<n; i++) {
        cin >> energy[i];
    }

    edges.resize(n+1);
    for(int i=0; i<n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }

    dp[0][1] = 0;
    dist[0][1] = 0;
    level[1] = 0;

    dfs(1, 0);

    for(int i=0; i<n; i++) {
        cout << solve(i+1, energy[i]) << "\n";
    }
}