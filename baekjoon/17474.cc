#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int INF = 1010101;

struct Node {
    ll mx, mx2, mxcnt, sum;
};

Node tree[INF*4];
ll arr[INF];

Node merge(Node l, Node r) {
    if(l.mx == r.mx) return {l.mx, max(l.mx2, r.mx2), l.mxcnt + r.mxcnt, l.sum + r.sum};
    if(l.mx > r.mx) swap(l, r);
    return {r.mx, max(l.mx, r.mx2), r.mxcnt, l.sum + r.sum};
}

void propagate(int s, int e, int i) {
    if(s == e) return;
    for(auto next : {i*2, i*2+1}) {
        if(tree[next].mx > tree[i].mx) {
            tree[next].sum -= (tree[next].mx - tree[i].mx) * tree[next].mxcnt;
            tree[next].mx = tree[i].mx;
        }
    }
}

void update(int s, int e, int i, int l, int r, ll v) {
    propagate(s, e, i);
    if(s > r || e < l || tree[i].mx <= v) return;
    if(s >= l && e <= r && tree[i].mx2 < v) {
        tree[i].sum -= (tree[i].mx - v) * tree[i].mxcnt;
        tree[i].mx = v;
        propagate(s, e, i);
        return;
    }
    int m = (s+e)/2;
    update(s, m, i*2, l, r, v);
    update(m+1, e, i*2+1, l, r, v);
    tree[i] = merge(tree[i*2], tree[i*2+1]);
}

ll querySum(int s, int e, int i, int l, int r) {
    propagate(s, e, i);
    if(s > r || e < l) return 0;
    if(s >= l && e <= r) return tree[i].sum;
    int m = (s+e)/2;
    return querySum(s, m, i*2, l, r) + querySum(m+1, e, i*2+1, l, r);
}

ll queryMax(int s, int e, int i, int l, int r) {
    propagate(s, e, i);
    if(s > r || e < l) return 0;
    if(s >= l && e <= r) return tree[i].mx;
    int m = (s+e)/2;
    return max(queryMax(s, m, i*2, l, r), queryMax(m+1, e, i*2+1, l, r));
}

void init(int s, int e, int i) {
    if(s == e) {
        tree[i] = {arr[s], -1, 1, arr[s]};
        return;
    }
    int m = (s+e)/2;
    init(s, m, i*2);
    init(m+1, e, i*2+1);
    tree[i] = merge(tree[i*2], tree[i*2+1]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> arr[i];
    }
    init(1, N, 1);
    int M;
    cin >> M;
    for(int i=0; i<M; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if(a == 1) {
            ll d;
            cin >> d;
            update(1, N, 1, b, c, d);
        }
        else if(a == 2) {
            cout << queryMax(1, N, 1, b, c) << '\n';
        }
        else {
            cout << querySum(1, N, 1, b, c) << '\n';
        }
    }
}