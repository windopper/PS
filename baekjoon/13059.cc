#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> edges;
int parent[18][200001];
long long depth[200001];

void dfs(int cur, int post) {
    for(int i=1; i<18; i++) {
        parent[i][cur] = parent[i-1][parent[i-1][cur]];
    }

    for(int next : edges[cur]) {
        if(next == post) continue;
        parent[0][next] = cur;
        depth[next] = depth[cur] + 1;
        dfs(next, cur);
    }
}

long long lca(int a, int b) {
    int originA = a;
    int originB = b;
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
            if(parent[i][a] != 0 && parent[i][a] != parent[i][b]) {
                a = parent[i][a];
                b = parent[i][b];
            }
        }
        lca = parent[0][a];
    }

    return depth[originA] + depth[originB] - depth[lca] * 2 + 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    edges.resize(n+1);
    for(int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    depth[1] = 1;
    parent[0][1] = 0;
    dfs(1, 0);

    long long ans = 0;

    for(int i=1; i<n+1; i++) {
        int cu = 2;
        while(1) {
            if(i * cu > n) break;
            ans += lca(i, i * cu);
            ++cu;
        }
    }

    cout << ans;

}