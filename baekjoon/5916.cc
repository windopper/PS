#include <bits/stdc++.h>

using namespace std;
int N, M;
const int INF = 100001;

long long tree[INF * 4] = {0, };
long long lazy[INF * 4] = {0, };

void propagate(int s, int e, int i) {
    if(lazy[i] != 0) {
        if(s != e) {
            lazy[i*2] += lazy[i];
            lazy[i*2+1] += lazy[i];
        }
        tree[i] += (e-s+1) * lazy[i];
        lazy[i] = 0;
    }
}

void segUpdate(int s, int e, int i, int l, int r, int v) {
    propagate(s, e, i);
    if(s > r || e < l) return;
    if(s >= l && e <= r) {
        lazy[i] += v;
        propagate(s, e, i);
        return;
    }
    int m = (s+e)/2;
    segUpdate(s, m, i*2, l, r, v);
    segUpdate(m+1, e, i*2+1, l, r, v);
    tree[i] = tree[i*2] + tree[i*2+1];
}

long long segQuery(int s, int e, int i, int l, int r) {
    propagate(s, e, i);
    if(s > r || e < l) return 0;
    if(s >= l && e <= r) return tree[i];
    int m = (s+e)/2;
    return segQuery(s, m, i*2, l, r) + segQuery(m+1, e, i*2+1, l, r);
}

vector<vector<int>> adj;
vector<int> g[INF];
int in[INF], dep[INF], par[INF], sz[INF], top[INF];
vector<int> vis(INF, 0);

void createGraph(int cur = 1) {
    vis[cur] = 1;
    for(int next : adj[cur]) {
        if(vis[next]) continue;
        vis[next] = 1;
        g[cur].push_back(next);
        createGraph(next);
    }
}

void hld(int cur = 1) {
    sz[cur] = 1;
    for(int& next : g[cur]) {
        dep[next] = dep[cur] + 1;
        par[next] = cur;
        hld(next);
        sz[cur] += sz[next];
        if(sz[next] > sz[g[cur][0]]) swap(next, g[cur][0]);
    }
}

int seq = 0;

void dfsOrdering(int cur = 1) {
    in[cur] = ++seq;
    for(int next : g[cur]) {
        top[next] = next == g[cur][0] ? top[cur] : next;
        dfsOrdering(next);
    }
}

void update(int l, int r) {
    while(top[l] ^ top[r]) {
        if(dep[top[l]] < dep[top[r]]) swap(l, r);
        int st = top[l];
        segUpdate(1, N, 1, in[st], in[l], 1);
        l = par[st];
    }
    if(dep[l] > dep[r]) swap(l, r);
    segUpdate(1, N, 1, in[l]+1, in[r], 1);
}

long long query(int l, int r) {
    long long ret = 0;
    while(top[l] ^ top[r]) {
        if(dep[top[l]] < dep[top[r]]) swap(l, r);
        int st = top[l];
        ret += segQuery(1, N, 1, in[st], in[l]);
        l = par[st];
    }
    if(dep[l] > dep[r]) swap(l, r);
    ret += segQuery(1, N, 1, in[l]+1, in[r]);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    adj.resize(N+1);
    for(int i=0; i<N-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    createGraph();
    hld();
    dfsOrdering();

    while(M--) {
        char w;
        int u, v;
        cin >> w >> u >> v;
        if(w == 'P') {
            update(u, v);
        }
        else {
            cout << query(u, v) << '\n';
        }
    }
}