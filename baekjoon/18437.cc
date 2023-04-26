#include <bits/stdc++.h>

using namespace std;
int N;

vector<vector<int>> adj;
int tree[400004];
int lazy[400004];
int in[100001], out[100001];
int seq = 0;

void dfs(int cur = 1) {
    in[cur] = ++seq;
    for(int next : adj[cur]) {
        dfs(next);
    }
    out[cur] = seq;
}

void propagate(int s, int e, int i) {
    if(lazy[i] != 0) {
        if(s != e) {
            lazy[i*2] = lazy[i];
            lazy[i*2+1] = lazy[i];
        }
        if(lazy[i] == 1) {
            tree[i] = (e-s+1);
        }
        else {
            tree[i] = 0;
        }
        lazy[i] = 0;
    }
}

void init(int s, int e, int i) {
    if(s == e) {
        tree[i] = 1;
        return;
    }
    int m = (s+e)/2;
    init(s, m, i*2);
    init(m+1, e, i*2+1);
    tree[i] = tree[i*2] + tree[i*2+1];
}

void update(int s, int e, int i, int l, int r, int v) {
    propagate(s, e, i);
    if(s > r || e < l) return;
    if(s >= l && e <= r) {
        lazy[i] = v;
        propagate(s, e, i);
        return;
    }
    int m = (s+e)/2;
    update(s, m, i*2, l, r, v);
    update(m+1, e, i*2+1, l, r, v);
    tree[i] = tree[i*2] + tree[i*2+1];
}

int query(int s, int e, int i, int l, int r) {
    propagate(s, e, i);
    if(s > r || e < l) return 0;
    if(s >= l && e <= r) return tree[i];
    int m = (s+e)/2;
    return query(s, m, i*2, l, r) + query(m+1, e, i*2+1, l, r);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    cin >> N;
    adj.resize(N+1);
    for(int i=1; i<=N; i++) {
        int t; cin >> t;
        if(t != 0) {
            adj[t].push_back(i);
        }
    }
    init(1, N, 1);
    dfs();
    int M;
    cin >> M;
    while(M--) {
        int a, b;
        cin >> a >> b;
        vector<int> arr;
        for(int cur : adj[b]) {
            arr.push_back(cur);
        }
        if(a == 1) {
            for(int cur : arr) {
                update(1, N, 1, in[cur], out[cur], 1);
            }
        }
        else if(a == 2) {
            for(int cur : arr) {
                update(1, N, 1, in[cur], out[cur], -1);
            }
        }
        else {
            int ans = 0;
            for(int cur : arr) {
                ans += query(1, N, 1, in[cur], out[cur]);
            }
            cout << ans << '\n';
        }
    }
}