#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj;
int parent[18][100001] = {0, };
int depth[100001];

void dfs(int cur, int post) {
    for(int i=1; i<18; i++) {
        parent[i][cur] = parent[i-1][parent[i-1][cur]];
    }

    for(int next : adj[cur]) {
        if(next == post) continue;
        depth[next] = depth[cur] + 1;
        parent[0][next] = cur;
        dfs(next, cur);
    }
}

pair<int, int> lca(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];
    for(int i=0; diff != 0; i++) {
        if(diff % 2 == 1) {
            a = parent[i][a];
        }
        diff /= 2;
    }

    int lca = a;

    if(a != b) {
        for(int i=17; i>=0; --i) {
            if(parent[i][a] != -1 && parent[i][a] != parent[i][b]) {
                a = parent[i][a];
                b = parent[i][b];
            }
        }
        lca = parent[0][a];
    }
    return {depth[lca], lca};
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    adj.resize(N+1);
    memset(parent, -1, sizeof(parent));
    for(int i=0; i<N-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[1] = 1;
    parent[0][1] = -1;
    dfs(1, 1);

    int M;
    cin >> M;
    for(int i=0; i<M; i++) {
        int r, u, v;
        cin >> r >> u >> v;
        vector<pair<int ,int>> vec;
        vec.push_back(lca(r, u));
        vec.push_back(lca(u, v));
        vec.push_back(lca(r, v));
        sort(vec.begin(), vec.end(), greater<>());
        cout << vec[0].second << '\n';
    }
}