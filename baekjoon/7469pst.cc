#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 100001;
const ll base = 1e9;

struct Node {
    ll v;
    Node *l, *r;
    Node() {
        l = r = NULL;
        v = 0;
    }
};

Node* root[INF];
ll arr[INF] = {0, };

void init(int s, int e, Node* cur) {
    if(s == e) {
        cur->v = 0;
        return;
    }
    int m = (s+e) >> 1;
    cur->l = new Node();
    cur->r = new Node();
    init(s, m, cur->l);
    init(m+1, e, cur->r);
    cur->v = cur->l->v + cur->r->v;
}

void add(int s, int e, Node* prv, Node* cur, int x) {
    if(s == e) {
        cur->v++;
        return;
    }
    int m = (s+e) >> 1;
    if(x <= m) {
        cur->l = new Node();
        cur->r = prv->r;
        add(s, m, prv->l, cur->l, x);
    }
    else {
        cur->r = new Node();
        cur->l = prv->l;
        add(m+1, e, prv->r, cur->r, x);
    }
    cur->v = cur->l->v + cur->r->v;
}

ll query(int s, int e, Node* l, Node* r, int K) {
    if(s == e) return s;
    int diff = r->l->v - l->l->v;
    int m = (s+e) >> 1;
    if(K <= diff) return query(s, m, l->l, r->l, K);
    else return query(m+1, e, l->r, r->r, K - diff);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, Q;
    cin >> N >> Q;
    ll carr[INF];
    map<int, int> st;
    map<int, int> rst;
    int idx = 1;
    for(int i=1; i<=N; i++) {
        cin >> arr[i];
        carr[i] = arr[i];
    }
    sort(arr+1, arr+1+N);
    for(int i=1; i<=N; i++) {
        if(st.find(arr[i]) == st.end()) {
            st[arr[i]] = idx;
            rst[idx++] = arr[i];
        }
    }
    root[0] = new Node();
    init(1, N, root[0]);
    for(int i=1; i<=N; i++) {
        add(1, N, root[i-1], root[i] = new Node(), st[carr[i]]);
    }
    for(int i=0; i<Q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << rst[query(1, N, root[a-1], root[b], c)] << '\n';
    }
}