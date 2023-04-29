#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;

struct Node {
    ll lval = -INF, rval = -INF, val = -INF, all = 0;
    Node() {}
    Node(int v) {
        lval = v;
        rval = v;
        val = v;
        all = v;
    }
};

Node* tree[1 << 18];
int base = 1 << 17;

Node* f(Node* l, Node* r) {
    Node* ret = new Node();
    ret->lval = max(l->lval, l->all + r->lval);
    ret->rval = max(r->rval, l->rval + r->all);
    ret->val = max(max(r->val, l->val), l->rval + r->lval);
    ret->all = l->all + r->all;
    return ret;
}

void update(int x, int v) {
    x |= base;
    tree[x]->all = tree[x]->rval = tree[x]->lval = tree[x]->val = v;
    while(x >>= 1) {
        tree[x] = f(tree[x << 1], tree[x << 1 | 1]);
    }
}

int query(int l, int r) {
    l |= base;
    r |= base;
    Node* retl = new Node();
    Node* retr = new Node();
    while(l <= r) {
        if(l & 1) retl = f(retl, tree[l++]);
        if(~r & 1) retr = f(tree[r--], retr);
        r >>= 1, l >>= 1;
    }
    return f(retl, retr)->val;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N;
    for(int i=0; i<1<<18; i++) {
        tree[i] = new Node();
    }
    for(int i=1; i<=N; i++) {
        int t;
        cin >> t;
        update(i, t);
    }
    cin >> M;
    for(int i=0; i<M; i++) {
        int u, v;
        cin >> u >> v;
        cout << query(u, v) << '\n';
    }
}