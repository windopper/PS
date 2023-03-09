#include <bits/stdc++.h>

using namespace std;
int N, M;
int parent[18][40001];
int dist[40001];
vector<vector<pair<int, int>>> edges;
int level[40001];

void dfs(int cur, int post) {
    for (int i = 1; i < 18; i++) {
        parent[i][cur] = parent[i - 1][parent[i - 1][cur]];
    }

    for (int i = 0; i < edges[cur].size(); i++) {
        pair<int, int> next = edges[cur][i];
        int nextNode = next.first;
        int nextDist = next.second;
        if (nextNode == post) continue;
        parent[0][nextNode] = cur;
        level[nextNode] = level[cur] + 1;
        dist[nextNode] = dist[cur] + nextDist;
        dfs(nextNode, cur);
    }
}

int solve(int a, int b) {
    int originalA = a, originalB = b;
    if (level[a] < level[b]) swap(a, b);
    int diff = level[a] - level[b];
    for (int i = 0; diff != 0; i++) {
        if (diff % 2 == 1) {
            a = parent[i][a];
        }
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

    int ret = dist[originalA] + dist[originalB] - 2 * dist[lca];

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    edges.resize(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        edges[u].push_back({v, c});
        edges[v].push_back({u, c});
    }

    parent[0][1] = 0;
    level[1] = 0;
    dist[1] = 0;
    dfs(1, 0);

    cin >> M;

    for (int i = 0; i < M; i++) {
        int c, d;
        cin >> c >> d;
        cout << solve(c, d) << "\n";
    }
}