#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const ll INF = 1e16;
int N;

struct Node {
    ll lval, rval, val, all;
};

Node tree[1 << 13];
int base = (1 << 12);

Node f(Node l, Node r) {
    ll lval = max(l.lval, l.all + r.lval);
    ll rval = max(r.rval, l.rval + r.all);
    ll val = max({l.val, r.val, l.rval + r.lval});
    ll all = l.all + r.all;
    return {lval, rval, val, all};
}

void update(int x, int v) {
    x |= base;
    Node &cur = tree[x];
    cur.lval += v;
    cur.rval += v;
    cur.val += v;
    cur.all += v;
    while(x >>= 1) {
        tree[x] = f(tree[x<<1], tree[x<<1|1]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<ll> xArr;
    vector<ll> yArr;
    vector<vector<ll>> points(N+1, vector<ll>(3));
    vector<vector<pii>> g(N+1);
    for(int i=0; i<N; i++) {
        cin >> points[i][0] >> points[i][1] >> points[i][2];
        xArr.push_back(points[i][0]);
        yArr.push_back(points[i][1]);
    }
    sort(xArr.begin(), xArr.end());
    sort(yArr.begin(), yArr.end());
    xArr.erase(unique(xArr.begin(), xArr.end()), xArr.end());
    yArr.erase(unique(yArr.begin(), yArr.end()), yArr.end());

    ll yseq = 1;
    for(int i=0; i<N; i++) {
        ll x, y, w;
        x = points[i][0]; y = points[i][1]; w = points[i][2];
        x = lower_bound(xArr.begin(), xArr.end(), x) - xArr.begin();
        y = lower_bound(yArr.begin(), yArr.end(), y) - yArr.begin();
        ++x, ++y;
        g[y].push_back({x, w});
        yseq = max(yseq, y);
    }

    ll ret = -INF;
    for(int i=1; i<=yseq; i++) {
        for(int l=0; l<(1<<13); l++) tree[l] = {0, 0, 0, 0};
        for(int j=i; j<=yseq; j++) {
            for(auto k : g[j]) {
                update(k.first, k.second);
            }
            ret = max(ret, tree[1].val);
        }
    }

    cout << ret << '\n';
}