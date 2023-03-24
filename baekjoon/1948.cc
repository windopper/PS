#include <bits/stdc++.h>
#include <limits>

using namespace std;
vector<vector<pair<int, int>>> edges;
vector<vector<pair<int, int>>> revs;
int s, e;
int dp[100001];
bool visited[100001];
int ans = 0;

int dfs(int cur) {
    if(cur == e) {
        return 0;
    }
    int &ret = dp[cur];
    if(ret != 0) return ret;
    for(int i=0; i<edges[cur].size(); i++) {
        int next = edges[cur][i].first;
        int nextTime = edges[cur][i].second;
        ret = max(ret, dfs(next) + nextTime);
    }
    return ret;
}

void bfs(int cur) {
    queue<pair<int, int>> q;
    q.push({0, cur});
    while(!q.empty()) {
        cur = q.back().second;
        int cost = q.back().first;
        q.pop();
        for(int i=0; i<edges[cur].size(); i++) {
            int next = edges[cur][i].first;
            int nextCost = edges[cur][i].second;
            dp[next] = max(dp[next], cost + nextCost);
            q.push({cost + nextCost, next});
        }
    }
}

void find_bfs(int cur) {
    queue<int> q;
    q.push(cur);
    visited[cur] = true;
    while(!q.empty()) {
        cur = q.back();
        q.pop();

        for(int i=0; i<revs[cur].size(); i++) {
            int prev = revs[cur][i].first;
            int prevTime = revs[cur][i].second;
            if(dp[cur] + prevTime == dp[prev]) {
                ++ans;
                if(!visited[prev]) {
                    visited[prev] = true;
                    q.push(prev);
                }
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
    }

    cin >> s >> e;

    dfs(s);
    find_bfs(e);
    cout << dp[s] << "\n" << ans;
}