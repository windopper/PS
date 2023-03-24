#include <bits/stdc++.h>
#include <limits>

using namespace std;
vector<vector<pair<int, int>>> edges;
vector<vector<pair<int, int>>> revs;
int s, e;
int dp[100001];
int indegree[100001];
bool visited[100001] = {false, };
int ans = 0;

void dfs(int cur) {
    if(visited[cur]) return;
    visited[cur] = true;
    for(int i=0; i<revs[cur].size(); i++) {
        int next = revs[cur][i].first;
        int nextCost = revs[cur][i].second;
        if(dp[cur] - nextCost == dp[next]) {
            dfs(next);
            ++ans;
        }
    }
}

void bfs(int cur) {
    queue<int> q;
    q.push(cur);
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        for(int i=0; i<edges[cur].size(); i++) {
            int next = edges[cur][i].first;
            int nextCost = edges[cur][i].second;
            dp[next] = max(dp[next], dp[cur] + nextCost);
            --indegree[next];
            if(indegree[next] == 0) {
                q.push(next);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    edges.resize(n+1);
    revs.resize(n+1);
    for(int i=0; i<m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        edges[u].push_back({v, t});
        revs[v].push_back({u, t});
        indegree[v]++;
    }

    cin >> s >> e;

    bfs(s);
    dfs(e);
    cout << dp[e] << "\n" << ans;
}