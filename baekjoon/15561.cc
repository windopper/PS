#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
int N, Q, U, V;

struct Node {
    ll lval, rval, mxval, all;
    Node() {}
    Node(int i) {
        lval = rval = mxval = all = i;
    }
    void set(int v) {
        lval = rval = mxval = all = v;
    }
};

Node* tree[400004];
int arr[100001];

Node* f(Node* l, Node* r) {
    Node* res = new Node();
    res->lval = max(l->lval, l->all + r->lval);
    res->rval = max(r->rval , r->all + l->rval);
    res->mxval = max({r->mxval, l->mxval, l->rval + r->lval});
    res->all = r->all + l->all;
    return res;
}

void init(int s, int e, int i) {
    if(s == e) {
        tree[i] = new Node(arr[s]);
        return;
    }
    int m = (s+e) >> 1;
    init(s, m, i*2);
    init(m+1, e, i*2+1);
    tree[i] = f(tree[i*2], tree[i*2+1]);
}

void update(int s, int e, int i, int ui, int ud) {
    if(s > ui || e < ui) return;
    if(s == e) {
        tree[i]->set(ud);
        return;
    }
    int m = (s+e) >> 1;
    update(s, m, i*2, ui, ud);
    update(m+1, e, i*2+1, ui, ud);
    tree[i] = f(tree[i<<1], tree[i<<1|1]);
}

Node* query(int s, int e, int i, int l, int r) {
    if(s > r || e < l) return new Node(-INF);
    if(s >= l && e <= r) return tree[i];
    int m = (s+e) >> 1;
    Node* ln = query(s, m, i*2, l, r);
    Node* rn = query(m+1, e, i*2+1, l, r);
    return f(ln, rn);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> Q >> U >> V;
    for(int i=1; i<=N; i++) {
        cin >> arr[i];
        arr[i] = arr[i] * U + V;
    }
    init(1, N, 1);
    while(Q--) {
        int c, a, b;
        cin >> c >> a >> b;
        if(c == 0) {
            cout << query(1, N ,1, a, b)->mxval - V << '\n';
        }
        else {
            update(1, N, 1, a, b * U + V);
        }
    }
}