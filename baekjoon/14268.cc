#include <bits/stdc++.h>

using namespace std;
int n, m;
int in[101010], out[101010];
int seq = 0;
vector<vector<int>> adj;
vector<bool> vis;
long long tree[400001] = {0, };
long long lazy[400001] = {0, };

void dfs(int cur = 1) {
    vis[cur] = true;
    in[cur] = ++seq;
    for(int next : adj[cur]) {
        if(vis[next]) continue;
        vis[next] = true;
        dfs(next);
    }
    out[cur] = seq;
}

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

void update(int s, int e, int i, int l, int r, int w) {
    propagate(s, e, i);
    if(s > r || e < l) return;
    if(s >= l && e <= r) {
        lazy[i] += w;
        propagate(s, e, i);
        return;
    }
    int m = (s+e)/2;
    update(s, m, i*2, l, r, w);
    update(m+1, e, i*2+1, l, r, w);
    tree[i] = tree[i*2] + tree[i*2+1];
}

long long query(int s, int e, int i, int target) {
    propagate(s, e, i);
    if(s > target || e < target) return 0;
    if(s == e) return tree[i];
    int m = (s+e)/2;
    return query(s, m, i*2, target) + query(m+1, e, i*2+1, target);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    adj.resize(n+1);
    for(int i=1; i<=n; i++) {
        int t;
        cin >> t;
        if(t != -1) {
            adj[t].push_back(i);
        }
    }

    vis.assign(n+1, false);
    dfs();

    while(m--) {
        int a, b, c;
        cin >> a >> b;
        if(a == 1) {
            cin >> c;
            update(1, n, 1, in[b], out[b], c);
        }
        else {
            cout << query(1, n, 1, in[b]) << '\n';
        }
    }
}