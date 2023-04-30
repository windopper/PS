#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<vector<int>> adj;

int in[100001], out[100001];
int seq = 0;

void dfsOrdering(int cur = 1, int post = 1) {
    in[cur] = ++seq;
    for(int next : adj[cur]) {
        if(next == post) continue;
        dfsOrdering(next, cur);
    }
    out[cur] = seq;
}

ll tree[1 << 19];
int base = 1 << 18;

void update(int x, ll v) {
    x |= base;
    tree[x] += v;
    while(x >>= 1) {
        tree[x] = tree[x<<1] + tree[x<<1|1];
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
    int N, M;
    cin >> N >> M;
    adj.resize(N+1);
    memset(tree, 0, sizeof(tree));
    for(int i=1; i<=N; i++) {
        int t; cin >> t;
        if(t != -1) {
            adj[t].push_back(i);
        }
    }
    dfsOrdering();
    while(M--) {
        int a, b;
        cin >> a >> b;
        if(a == 1) {
            int c;
            cin >> c;
            update(in[b], c);
        }
        else {
            cout << query(in[b], out[b]) << '\n';
        }
    }
}