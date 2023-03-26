#include <bits/stdc++.h>

using namespace std;
int N, Q;
vector<vector<pair<int, int>>> edges;
int level[100001];
int parent[18][100001];
int cost[100001];

void dfs(int cur, int post) {
    for(int i=1; i<18; i++) {
        parent[i][cur] = parent[i-1][parent[i-1][cur]];
    }
    for(int i=0; i<edges[cur].size(); i++) {
        int next = edges[cur][i].first;
        int nextCost = edges[cur][i].second;
        if(next == post) continue;
        parent[0][next] = cur;
        level[next] = level[cur] + 1;
        cost[next] = cost[cur] + nextCost;
        dfs(next, cur);
    }
}

int solve(int a, int b) {
    int originalA = a;
    int originalB = b;
    if(level[a] < level[b]) swap(a, b);
    int diff = level[a] - level[b];
    for(int i=0; diff != 0; i++) {
        if(diff % 2 == 1) a = parent[i][a];
        diff /= 2;
    }

    int lca = a;
    if(a != b) {
        for(int i=17; i>=0; --i) {
            if(parent[i][a] != 0 && parent[i][a] != parent[i][b]) {
                a = parent[i][a];
                b = parent[i][b];
            }
        }
        lca = parent[0][a];
    }
    return cost[originalA] + cost[originalB] - 2 * cost[lca];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> Q;
    edges.resize(N+1);
    for(int i=0; i<N-1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        edges[u].push_back({v, c});
        edges[v].push_back({u, c});
    }

    level[1] = 1;
    parent[0][1] = 0;
    cost[1] = 0;
    dfs(1, 1);

    for(int i=0; i<Q; i++) {
        int a, b;
        cin >> a >> b;

        cout << solve(a, b) << "\n";
    }
}