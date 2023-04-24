#include <bits/stdc++.h>

using namespace std;
typedef unsigned int ui;
int N, M;
const int INF = 500001;
ui tree[INF*4];
ui lazy[INF*4];

int in[INF], out[INF], inToN[INF];
vector<vector<int>> adj;
int seq = 0;

void dfsOrdering(int cur = 1) {
    in[cur] = ++seq;
    inToN[seq] = cur;
    for(int next : adj[cur]) {
        dfsOrdering(next);
    }
    out[cur] = seq;
}

void update(int s, int e, int i, int ui, int ud) {
    if(s > ui || e < ui) return;
    if(s == e) {
        tree[i] = ud;
        return;
    }
    int m = (s+e)/2;
    update(s, m, i*2, ui, ud);
    update(m+1, e, i*2+1, ui, ud);
    tree[i] = tree[i*2] + tree[i*2+1];
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

void update(int s, int e, int i, int l, int r, int v) {
    propagate(s, e, i);
    if(s > r || e < l) return;
    if(s >= l && e <= r) {
        lazy[i] += v;
        propagate(s, e, i);
        return;
    }
    int m = (s+e)/2;
    update(s, m, i*2, l, r, v);
    update(m+1, e, i*2+1, l, r, v);
    tree[i] = tree[i*2] + tree[i*2+1];
}

ui query(int s, int e, int i, int l, int r) {
    propagate(s, e, i);
    if(s > r || e < l) return 0;
    if(s >= l && e <= r) return tree[i];
    int m = (s+e)/2;
    return query(s, m, i*2, l, r) + query(m+1, e, i*2+1, l, r);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    adj.resize(N+1);
    vector<int> temp;

    for(int i=1; i<=N; i++) {
        int m;
        cin >> m;
        if(i != 1) {
            int num;
            cin >> num;
            adj[num].push_back(i);
        }
        temp.push_back(m);
    }

    dfsOrdering();

    for(int i=0; i<temp.size(); i++) {
        update(1, N, 1, in[i+1], temp[i]);
    }

    while(M--) {
        char s;
        int a, x;
        cin >> s >> a;
        if(s == 'p') {
            cin >> x;
            update(1, N, 1, in[a], out[a], x);
            update(1, N, 1, in[a], in[a], -x);
        }
        else {
            cout << query(1, N, 1, in[a], in[a]) << '\n';
        }
    }
}