#include <bits/stdc++.h>

using namespace std;
vector<vector<pair<int, int>>> edges;
int parent[18][100001];
int level[100001];
int minDist[18][100001];
int maxDist[18][100001];

void dfs(int cur, int post) {
    for (int i = 1; i < 18; i++) {
        parent[i][cur] = parent[i - 1][parent[i - 1][cur]];
        minDist[i][cur] = min(minDist[i - 1][cur], minDist[i - 1][parent[i - 1][cur]]);
        maxDist[i][cur] = max(maxDist[i - 1][cur], maxDist[i - 1][parent[i - 1][cur]]);
    }

    for (int i = 0; i < edges[cur].size(); i++) {
        int next = edges[cur][i].first;
        int nextDist = edges[cur][i].second;
        if (next == post) continue;
        parent[0][next] = cur;
        level[next] = level[cur] + 1;
        minDist[0][next] = nextDist;
        maxDist[0][next] = nextDist;
        dfs(next, cur);
    }
}

void solve(int a, int b) {
    if (a == b) {
        cout << 0 << " " << 0 << "\n";
        return;
    }
    int minRet = 1000000;
    int maxRet = 0;
    int originalA = a, originalB = b;
    if (level[a] < level[b]) swap(a, b);

    int diff = level[a] - level[b];
    for (int i = 0; diff != 0; i++) {
        if (diff % 2 == 1) {
            minRet = min(minRet, minDist[i][a]);
            maxRet = max(maxRet, maxDist[i][a]);
            a = parent[i][a];
        }
        diff /= 2;
    }

    int lca = a;

    if (a != b) {
        for (int i = 17; i >= 0; --i) {
            if (parent[i][a] != 0 && parent[i][a] != parent[i][b]) {
                minRet = min(minRet, minDist[i][a]);
                maxRet = max(maxRet, maxDist[i][a]);
                minRet = min(minRet, minDist[i][b]);
                maxRet = max(maxRet, maxDist[i][b]);
                a = parent[i][a];
                b = parent[i][b];
            }
        }
        lca = parent[0][a];
        minRet = min(minRet, minDist[0][a]);
        maxRet = max(maxRet, maxDist[0][a]);
        minRet = min(minRet, minDist[0][b]);
        maxRet = max(maxRet, maxDist[0][b]);
    }
    cout << minRet << " " << maxRet << "\n";
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

    int root = 1;
    parent[0][root] = 0;
    level[root] = 0;
    for (int i = 0; i < 18; i++) {
        maxDist[i][0] = 0;
        minDist[i][0] = 1000000;
        maxDist[i][root] = 0;
        minDist[i][root] = 1000000;
    }

    dfs(root, 0);
    int K;
    cin >> K;
    for (int i = 0; i < K; i++) {
        int c, d;
        cin >> c >> d;
        solve(c, d);
    }
}