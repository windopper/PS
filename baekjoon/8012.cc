#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<vector<int>> edges;
int parent[30001];
int level[30001];

void dfs(int cur, int post) {
    for (int i = 0; i < edges[cur].size(); i++) {
        int next = edges[cur][i];
        if (post == next) continue;
        level[next] = level[cur] + 1;
        parent[next] = cur;
        dfs(next, cur);
    }
}

int solve(int a, int b) {
    int originalA = a, originalB = b;
    if (level[a] < level[b]) swap(a, b);
    int diff = level[a] - level[b];
    for (; diff > 0; diff--) {
        a = parent[a];
    }

    int lca = a;
    if (a != b) {
        while (parent[a] != 0 && parent[a] != parent[b]) {
            a = parent[a];
            b = parent[b];
        }
        lca = parent[a];
    }
    return level[originalA] + level[originalB] - 2 * level[lca];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    edges.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    parent[1] = 0;
    level[1] = 0;
    dfs(1, 0);

    cin >> m;
    vector<int> visit(m);
    for (int i = 0; i < m; i++) cin >> visit[i];

    int ans = 0;

    for (int i = 0; i < m - 1; i++) {
        ans += solve(visit[i], visit[i + 1]);
    }

    cout << ans << "\n";
}