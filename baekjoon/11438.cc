#include <bits/stdc++.h>

using namespace std;
int N;
vector<vector<int>> arr;
int parent[18][100001];
int level[100001];

void dfs(int cur, int post, int lv) {
    parent[0][cur] = post;
    level[cur] = lv;

    for (int i = 1; i < 18; i++) {
        parent[i][cur] = parent[i - 1][parent[i - 1][cur]];
    }

    for (int i = 0; i < arr[cur].size(); i++) {
        int next = arr[cur][i];
        if (next == post) continue;
        dfs(next, cur, lv + 1);
    }
}

int lca(int a, int b) {
    if (level[a] < level[b]) swap(a, b);
    int diff = level[a] - level[b];
    for (int i = 0; diff != 0; i++) {
        if (diff % 2 == 1) a = parent[i][a];
        diff /= 2;
    }

    int ret = a;
    if (a != b) {
        for (int i = 17; i >= 0; --i) {
            if (parent[i][a] != 0 && parent[i][a] != parent[i][b]) {
                a = parent[i][a];
                b = parent[i][b];
            }
        }
        ret = parent[0][a];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    arr.resize(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    fill_n(level, 100001, -1);

    int root = 1;
    dfs(root, 0, 0);

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }
}