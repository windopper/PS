#include <bits/stdc++.h>

using namespace std;
typedef unsigned long ll;

int N, Q;
const int INF = 500001;
ll tree[INF*4];
pair<ll, ll> lazy[INF*4];
// {add, mul}
// {0, 1};
const ll MOD = 1ul << 32;

void propagate(int s, int e, int i) {
    if(lazy[i].first != 0 || lazy[i].second != 1) {
        if(s != e) {
            lazy[i*2].first = (lazy[i].first + (lazy[i*2].first * lazy[i].second) % MOD) % MOD;
            lazy[i*2].second = (lazy[i].second * lazy[i*2].second) % MOD;
            lazy[i*2+1].first = (lazy[i].first + (lazy[i*2+1].first * lazy[i].second) % MOD) % MOD;
            lazy[i*2+1].second = (lazy[i].second * lazy[i*2+1].second) % MOD;
        }
    }
    tree[i] = ((lazy[i].second * tree[i]) % MOD + ((e-s+1) * lazy[i].first) % MOD) % MOD;
    lazy[i] = {0, 1};
}

void segUpdateSum(int s, int e, int i, int l, int r, long long v) {
    propagate(s, e, i);
    if(s > r || e < l) return;
    if(s >= l && e <= r) {
        lazy[i] = {(lazy[i].first + v) % MOD, lazy[i].second};
        propagate(s, e, i);
        return;
    }
    int m = (s+e)/2;
    segUpdateSum(s, m, i*2, l, r, v);
    segUpdateSum(m+1, e, i*2+1, l, r, v);
    tree[i] = (tree[i*2] + tree[i*2+1]) % MOD;
}

void segUpdateMul(int s, int e, int i, int l, int r, long long v) {
    propagate(s, e, i);
    if(s > r || e < l) return;
    if(s >= l && e <= r) {
        lazy[i] = {(lazy[i].first * v) % MOD, (lazy[i].second * v) % MOD};
        propagate(s, e, i);
        return;
    }
    int m = (s+e)/2;
    segUpdateMul(s, m, i*2, l, r, v);
    segUpdateMul(m+1, e, i*2+1, l, r, v);
    tree[i] = (tree[i*2] + tree[i*2+1]) % MOD;
}

long long segQuery(int s, int e, int i, int l, int r) {
    propagate(s, e, i);
    if(s > r || e < l) return 0;
    if(s >= l && e <= r) return tree[i] % MOD;
    int m = (s+e)/2;
    return (segQuery(s, m, i*2, l, r) + segQuery(m+1, e, i*2+1, l, r)) % MOD;
}

vector<vector<int>> adj;
vector<int> g[INF];
int in[INF], par[INF], dep[INF], out[INF], sz[INF], top[INF];
int seq = 0;
vector<bool> vis(INF, false);

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

void dfsOrdering(int cur = 1) {
    in[cur] = ++seq;
    for(int next : g[cur]) {
        top[next] = next == g[cur][0] ? top[cur] : next;
        dfsOrdering(next);
    }
    out[cur] = seq;
}

void updateSum(int x, ll v) {
    segUpdateSum(1, N, 1, in[x], out[x], v);
}

void updateSum(int l, int r, ll v) {
    while(top[l] ^ top[r]) {
        if(dep[top[l]] < dep[top[r]]) swap(l, r);
        int st = top[l];
        segUpdateSum(1, N, 1, in[st], in[l], v);
        l = par[st];
    }
    if(dep[l] > dep[r]) swap(l, r);
    segUpdateSum(1, N, 1, in[l], in[r], v);
}

void updateMul(int x, ll v) {
    segUpdateMul(1, N, 1, in[x], out[x], v);
}

void updateMul(int l, int r, ll v) {
    while(top[l] ^ top[r]) {
        if(dep[top[l]] < dep[top[r]]) swap(l, r);
        int st = top[l];
        segUpdateMul(1, N, 1, in[st], in[l], v);
        l = par[st];
    }
    if(dep[l] > dep[r]) swap(l, r);
    segUpdateMul(1, N, 1, in[l], in[r], v);
}

ll query(int x) {
    return segQuery(1, N, 1, in[x], out[x]);
}

ll query(int l, int r) {
    ll ret = 0;
    while(top[l] ^ top[r]) {
        if(dep[top[l]] < dep[top[r]]) swap(l, r);
        int st = top[l];
        ret = (ret + segQuery(1, N, 1, in[st], in[l])) % MOD;
        l = par[st];
    }
    if(dep[l] > dep[r]) swap(l, r);
    ret = (ret + segQuery(1, N, 1, in[l], in[r])) % MOD;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> Q;
    adj.resize(N+1);
    for(int i=0; i<N-1; i++) {
        int S, E;
        cin >> S >> E;
        adj[S].push_back(E);
        adj[E].push_back(S);
    }

    createGraph();
    hld();
    dfsOrdering();

    while(Q--) {
        int i, X, V, t;
        cin >> i >> X;
        if(i == 1) {
            cin >> V;
            updateSum(X, V);
        }
        else if(i == 2) {
            cin >> V >> t;
            updateSum(X, V, t);
        }
        else if(i == 3) {
            cin >> V;
            updateMul(X, V);
        }
        else if(i == 4) {
            cin >> V >> t;
            updateMul(X, V, t);
        }
        else if(i == 5) {
            cout << query(X) << '\n';
        }
        else {
            cin >> V;
            cout << query(X, V) << '\n';
        }
    }
}
