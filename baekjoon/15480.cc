#include <bits/stdc++.h>

using namespace std;
int N;
vector<vector<int>> edges;
int parent[18][100001];
int level[100001];

void dfs(int cur, int post) {
    for (int i = 1; i < 18; i++) {
        parent[i][cur] = parent[i - 1][parent[i - 1][cur]];
    }

    for (int i = 0; i < edges[cur].size(); i++) {
        int next = edges[cur][i];
        if (next == post) continue;
        parent[0][next] = cur;
        level[next] = level[cur] + 1;
        dfs(next, cur);
    }
}

int lca(int a, int b) {
    if (level[a] < level[b]) swap(a, b);
    int diff = level[a] - level[b];
    for (int i = 0; diff != 0; i++) {
        if (diff % 2 == 1) a = parent[i][a];
        diff /= 2;
    }

    int lca = a;
    if (a != b) {
        for (int i = 17; i >= 0; i--) {
            if (parent[i][a] != 0 && parent[i][a] != parent[i][b]) {
                a = parent[i][a];
                b = parent[i][b];
            }
        }
        lca = parent[0][a];
    }

    return lca;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    edges.resize(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int r, u, v;
        cin >> r >> u >> v;

        fill_n(level, 100001, 0);
        for (int i = 0; i < 18; i++) {
            for (int j = 0; j < 100001; j++) parent[i][j] = 0;
        }

        dfs(r, 0);

        cout << lca(u, v) << "\n";
    }
}