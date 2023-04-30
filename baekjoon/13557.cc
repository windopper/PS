#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = 1e9;
int N;

struct Node {
    ll lval, rval, val, all;
};

Node tree[1<<18];
int base = 1 << 17;

Node f(Node& l, Node& r) {
    Node res;
    res.lval = max(l.lval, l.all + r.lval);
    res.rval = max(r.rval, l.rval + r.all);
    res.val = max({l.val, r.val, l.rval + r.lval});
    res.all = l.all + r.all;
    return res;
}

void update(int x, ll v) {
    x |= base;
    Node &cur = tree[x];
    cur.lval = v;
    cur.rval = v;
    cur.val = v;
    cur.all = v;
    while(x >>= 1) {
        tree[x] = f(tree[x << 1], tree[x << 1 | 1]);
    }
}

Node query(int l, int r) {
    l |= base;
    r |= base;
    Node lres = {-INF, -INF, -INF, 0};
    Node rres = {-INF, -INF, -INF, 0};
    while(l <= r) {
        if(l & 1) lres = f(lres, tree[l++]);
        if(~r & 1) rres = f(tree[r--], rres);
        l >>= 1, r >>= 1;
    }
    return f(lres, rres);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<(1<<18); i++) tree[i] = {-INF, -INF, -INF, 0};
    for(int i=0; i<N; i++) {
        ll t; cin >> t;
        update(i+1, t);
    }

    int M;
    cin >> M;
    while(M--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll res;
        if(y1 > x2) {
            swap(y1, x2);
            Node l = query(x1, y1-1);
            Node m = query(y1, x2);
            Node r = query(x2+1, y2);
            res = max({l.rval+m.lval, l.rval+m.all+r.lval,
                        m.val,
                        m.rval+r.lval});
        }
        else if(y1 < x2) {
            Node l = query(x1, y1);
            Node m = query(y1+1, x2-1);
            Node r = query(x2, y2);
            res = max({l.rval+m.all+r.lval});
        }
        else {
            Node l = query(x1, y1-1);
            Node r = query(x2, y2);
            res = max(l.rval + r.lval, r.lval);
        }

        cout << res << '\n';
    }
}