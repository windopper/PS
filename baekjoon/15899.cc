#include <bits/stdc++.h>

using namespace std;
const int MOD = 1000000007;
const int INF = 200001;

vector<vector<int>> tree(INF*4);
int arr[INF];

vector<vector<int>> adj;
int in[INF], out[INF];
int seq = 0;

void dfsOrdering(int cur = 1, int post = 1) {
    in[cur] = ++seq;
    for(int next : adj[cur]) {
        if(next == post) continue;
        dfsOrdering(next, cur);
    }
    out[cur] = seq;
}

void init(int s, int e, int i) {
    if(s == e) {
        tree[i].push_back(arr[s]);
        return;
    }
    int m = (s+e)/2;
    init(s, m, i*2);
    init(m+1, e, i*2+1);
    vector<int>& l = tree[i*2];
    vector<int>& r = tree[i*2+1];
    tree[i].resize(e-s+1);
    merge(l.begin(), l.end(), r.begin(), r.end(), tree[i].begin());
}

int query(int s, int e, int i, int l, int r, int target) {
    if(s > r || e < l) return 0;
    if(s >= l && e <= r) return upper_bound(tree[i].begin(), tree[i].end(), target) - tree[i].begin(); 
    int m = (s+e)/2;
    return (query(s, m, i*2, l, r, target) + query(m+1, e, i*2+1, l, r, target)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M, C;
    cin >> N >> M >> C;
    vector<int> colors(N+1);
    for(int i=1; i<=N; i++) {
        cin >> colors[i];
    }
    adj.resize(N+1);
    for(int i=0; i<N-1; i++) {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfsOrdering();
    for(int i=1; i<=N; i++) {
        arr[in[i]] = colors[i];
    }
    init(1, N, 1);

    long long ret = 0;
    for(int i=0; i<M; i++) {
        int v, c;
        cin >> v >> c;
        ret += query(1, N, 1, in[v], out[v], c);
        ret %= MOD;
    }

    cout << ret;
}