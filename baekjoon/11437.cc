#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> edges;
int parent[50001];
int depth[50001];

void dfs(int cur, int post) {
    for(int next : edges[cur]) {
        if(next == post) continue;
        parent[next] = cur;
        depth[next] = depth[cur] + 1;
        dfs(next, cur);
    }
}

int lca(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);

    while(1) {
        if(depth[a] == depth[b]) break;
        a = parent[a];
    }
    
    while(a != b) {
        a = parent[a];
        b = parent[b];
    }

    return a;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N;
    edges.resize(N+1);
    for(int i=0; i<N-1; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    parent[1] = 0;
    depth[1] = 1;
    dfs(1, 1);

    cin >> M;

    for(int i=0; i<M; i++) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }
}