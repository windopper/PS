#include <bits/stdc++.h>
#include <limits>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const ll INF = 1e16;
int N;

struct Node {
    ll lval, rval, val, all;
    Node(ll v) {
        lval = rval = val = all = v;
    }
};

Node* tree[1 << 18];
int base = 1 << 17;

Node* f(Node* l, Node* r) {
    Node* res = new Node(-INF);
    res->lval = max(l->lval, l->all + r->lval);
    res->rval = max(r->rval, l->rval + r->all);
    res->val = max({l->val, r->val, l->rval + r->lval});
    res->all = l->all + r->all;
    return res;
}

Node* query(int s, int e, int i, int l, int r) {
    if(s > r || e < l) return new Node(-INF);
    if(s >= l && e <= r) return tree[i];
    int m = (s+e) >> 1;
    return f(query(s, m, i*2, l, r) , query(m+1, e, i*2+1, l, r));
}

void update(int s, int e, int i, int ui, int ud) {
    if(s > ui || e < ui) return;
    if(s == e) {
        Node* cur = tree[i];
        cur->lval += ud;
        cur->rval += ud;
        cur->val += ud;
        cur->all += ud;
        return;
    }
    int m = (s+e) >> 1;
    update(s, m, i*2, ui, ud);
    update(m+1, e, i*2+1, ui, ud);
    tree[i] = f(tree[i << 1], tree[i << 1 | 1]);
}

void update(int x, int v) {
    x |= base;
    Node* cur = tree[x];
    cur->lval += v;
    cur->rval += v;
    cur->val += v;
    cur->all += v;
    while(x >>= 1) {
        tree[x] = f(tree[x<<1], tree[x<<1|1]);
    }
}

Node* query(int l, int r) {
    l |= base;
    r |= base;
    Node* lnode = new Node(-INF);
    Node* rnode = new Node(-INF);
    while(l <= r) {
        if(l & 1) lnode = f(lnode, tree[l++]);
        if(~r & 1) rnode = f(tree[r--], rnode);
        l >>= 1, r >>= 1;
    }
    return f(lnode, rnode);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<pii> xArr;
    vector<pii> yArr;
    vector<vector<ll>> points(N+1, vector<ll>(3));
    for(int i=0; i<N; i++) {
        ll x, y, c;
        cin >> x >> y >> points[i][2];
        xArr.push_back({x, i});
        yArr.push_back({y, i});
    }

    sort(xArr.begin(), xArr.end());
    sort(yArr.begin(), yArr.end());

    int xseq = 1, yseq = 1;
    for(int i=0; i<N; i++) {
        if(i != 0 && xArr[i-1].first != xArr[i].first) {
            ++xseq;
        }
        if(i != 0 && yArr[i-1].first != yArr[i].first) {
            ++yseq;
        }
        points[xArr[i].second][0] = xseq;
        points[yArr[i].second][1] = yseq;
    }
    vector<vector<pii>> datas(N+1);
    for(int i=0; i<N; i++) {
        datas[points[i][1]].push_back({points[i][0], points[i][2]});
    }
    ll ret = numeric_limits<ll>::min();
    for(int i=1; i<=yseq; i++) {
        for(int l=1; l<1<<18; l++) {
            tree[l] = new Node(0);
        }
        for(int j=i; j<=yseq; j++) {
            for(auto k : datas[j]) {
                update(1, N, 1, k.first, k.second);
            }
            ret = max(ret, query(1, N, 1, 1, N)->val);
        }
    }

    cout << ret;
}