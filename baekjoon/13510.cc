#include <bits/stdc++.h>

using namespace std;
int N;

vector<pair<int, int>> edge;
int tree[1 << 18] = {0, };
int ts = 1 << 17;
vector<vector<int>> adj;

void segUpdate(int x, int v) {
    x |= ts;
    tree[x] = v;
    while(x >>= 1) {
        tree[x] = max(tree[x << 1], tree[x << 1 | 1]);
    };
}

int segQuery(int a, int b) {
    a |= ts;
    b |= ts;
    int ret = 0;
    while(a <= b) {
        if(a & 1) ret = max(ret, tree[a++]);
        if(~b & 1) ret = max(ret, tree[b--]); 
        a >>= 1;
        b >>= 1;
    }
    return ret;
}

int sts[100001], dep[100001], parent[100001], in[100001], out[100001], top[100001];
vector<int> g[100001];
int seq = 0;

int vis[100001];
void dfs(int cur = 1) {
    vis[cur] = 1;
    for(auto next : adj[cur]) {
        if(vis[next]) continue;
        vis[next] = 1;
        g[cur].push_back(next);
        dfs(next);
    }
}

void dfs1(int cur = 1) {
    sts[cur] = 1;
    for(auto& next : g[cur]) {
        dep[next] = dep[cur] + 1;
        parent[next] = cur;
        dfs1(next);
        sts[cur] += sts[next];
        if(sts[next] > sts[g[cur][0]]) swap(next, g[cur][0]);
    }
}

void dfs2(int cur = 1) {
    in[cur] = ++seq;
    for(auto next : g[cur]) {
        top[next] = next == g[cur][0] ? top[cur] : next;
        dfs2(next);
    }
    out[cur] = seq;
}

void update(int x, int v) {
    segUpdate(in[x], v);
}

int query(int a, int b) {
    int ret = 0;
    while(top[a] ^ top[b]) {
        if(dep[top[a]] < dep[top[b]]) swap(a, b);
        int st = top[a];
        ret = max(ret, segQuery(in[st], in[a]));
        a = parent[st];
    }
    if(dep[a] > dep[b]) swap(a, b);
    ret = max(ret, segQuery(in[a]+1, in[b]));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    adj.resize(N+1);
    edge.resize(N+1);
    vector<int> weight(N+1);
    for(int i=1; i<N; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[i] = {u, v};
        adj[u].push_back(v);
        adj[v].push_back(u);
        weight[i] = w;
    }

    dfs();
    dfs1();
    dfs2();

    for(int i=1; i<N; i++) {
        int u = edge[i].first;
        int v = edge[i].second;
        if(parent[u] ^ v) swap(u, v);
        update(u, weight[i]);
    }

    int M;
    cin >> M;
    for(int i=0; i<M; i++) {
        int a, b, c;
        // 1 i c update
        // 2 u v query
        cin >> a >> b >> c;
        

        if(a == 1) {
            int u = edge[b].first;
            int v = edge[b].second;
            if(parent[u] ^ v) swap(u, v);
            update(u, c);
        } 
        else {
            cout << query(b, c) << '\n';
        }
    }
}