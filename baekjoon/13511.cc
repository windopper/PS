#include <bits/stdc++.h>

using namespace std;
vector<vector<pair<int, int>>> edges;
int parent[18][100001];
int level[100001];
long long dist[100001];

void dfs(int cur, int post) {
    for (int i = 1; i < 18; i++) {
        parent[i][cur] = parent[i - 1][parent[i - 1][cur]];
    }

    for (int i = 0; i < edges[cur].size(); i++) {
        int nextNode = edges[cur][i].first;
        int nextDist = edges[cur][i].second;
        if (nextNode == post) continue;
        parent[0][nextNode] = cur;
        level[nextNode] = level[cur] + 1;
        dist[nextNode] = dist[cur] + nextDist;
        dfs(nextNode, cur);
    }
}

int queryLCA(int a, int b) {
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
        for (int i = 17; i >= 0; --i) {
            if (parent[i][a] != 0 && parent[i][a] != parent[i][b]) {
                a = parent[i][a];
                b = parent[i][b];
            }
        }
        lca = parent[0][a];
    }
    return lca;
}

long long costQuery(int a, int b) {
    int lca = queryLCA(a, b);
    return dist[a] + dist[b] - 2 * dist[lca];
}

int findQuery(int a, int b, int k) {
    --k;
    int lca = queryLCA(a, b);
    int ret;
    int left = level[a] - level[lca];
    int right = level[b] - level[lca];
    if (k <= left) {
        ret = a;
        for (int i = 0; k != 0; i++) {
            if (k % 2 == 1) {
                ret = parent[i][ret];
            }
            k /= 2;
        }
    } else {
        k = left + right - k;
        ret = b;
        for (int i = 0; k != 0; i++) {
            if (k % 2 == 1) {
                ret = parent[i][ret];
            }
            k /= 2;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    edges.resize(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        edges[u].push_back({v, c});
        edges[v].push_back({u, c});
    }

    level[1] = 1;
    dist[1] = 0;
    dfs(1, 0);

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int c, u, v;
        cin >> c >> u >> v;
        if (c == 1) {
            cout << costQuery(u, v) << "\n";
        } else {
            int k;
            cin >> k;
            cout << findQuery(u, v, k) << "\n";
        }
    }
}