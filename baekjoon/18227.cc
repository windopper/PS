#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll tree[1 << 20];
int base = 1 << 19;
vector<vector<int>> g;
ll in[200002], out[200002], dep[200002];
int seq = 0;

void dfsOrdering(int cur, int d, int post) {
    in[cur] = ++seq;
    dep[cur] = d;
    for(int next : g[cur]) {
        if(next == post) continue;
        dfsOrdering(next, d+1, cur);
    }
    out[cur] = seq;
}

void update(int x, ll v) {
    x |= base;
    tree[x] += v;
    while(x >>= 1) {
        tree[x] = tree[x << 1] + tree[x << 1 | 1];
    }
}

ll query(int l, int r) {
    l |= base;
    r |= base;
    ll ret = 0;
    while(l <= r) {
        if(l & 1) ret += tree[l++];
        if(~r & 1) ret += tree[r--];
        l >>= 1, r >>= 1;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, C;
    cin >> N >> C;
    g.resize(N+1);
    memset(tree, 0, sizeof(tree));
    for(int i=0; i<N-1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfsOrdering(C, 1, C);

    int Q;
    cin >> Q;
    while(Q--) {
        int a , b;
        cin >> a >> b;
        if(a == 1) {
            update(in[b], 1);
        }
        else {
            cout << query(in[b], out[b]) * dep[b] << '\n';
        }
    }
}