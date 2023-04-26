#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<vector<int>> adj;
long long lazy[400004] = {0, };
long long tree[400004] = {0, };
long long lazy2[400004] = {0, };
long long tree2[400004] = {0, };
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
            lazy[i*2] += lazy[i];
            lazy[i*2+1] += lazy[i];
        }
        tree[i] += (e-s+1) * lazy[i];
        lazy[i] = 0;
    }
}

void updateDown(int s, int e, int i, int l, int r, int w) {
    propagate(s, e, i);
    if(s > r || e < l) return;
    if(s >= l && e <= r) {
        lazy[i] += w;
        propagate(s, e, i);
        return;
    }
    int m = (s+e)/2;
    updateDown(s, m, i*2, l, r, w);
    updateDown(m+1, e, i*2+1, l, r, w);
    tree[i] = tree[i*2] + tree[i*2+1];
}

void updateUp(int s, int e, int i, int ui, int ud) {
    if(s > ui || e < ui) return;
    if(s == e) {
        tree2[i] += ud;
        return;
    }
    int m = (s+e)/2;
    updateUp(s, m, i*2, ui, ud);
    updateUp(m+1, e, i*2+1, ui, ud);
    tree2[i] = tree2[i*2] + tree2[i*2+1];
}

long long query(int s, int e, int i, int target) {
    propagate(s, e, i);
    if(s > target || e < target) return 0;
    if(s == e) return tree[i];
    int m = (s+e)/2;
    return query(s, m, i*2, target) + query(m+1, e, i*2+1, target);
}

long long query2(int s, int e, int i, int l, int r) {
    if(s > r || e < l) return 0;
    if(s >= l && e <= r) return tree2[i];
    int m = (s+e)/2;
    return query2(s, m, i*2, l, r) + query2(m+1, e, i*2+1, l, r);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    adj.resize(n+1);
    for(int i=1; i<=n; i++) {
        int t; cin >> t;
        if(t != -1) {
            adj[t].push_back(i);
        }
    }

    dfs();

    bool up = false;
    while(m--) {
        int a, b, c;
        cin >> a;
        if(a == 1) {
            cin >> b >> c;
            if(up) {
                updateUp(1, n, 1, in[b], c);
            }   
            else {
                updateDown(1, n, 1, in[b], out[b], c);
            }
        }
        else if(a == 2) {
            cin >> b;
            cout << query(1, n, 1, in[b]) + query2(1, n, 1, in[b], out[b]) << '\n';
        }
        else {
            if(up) up = false;
            else up = true;
        }
    }
}