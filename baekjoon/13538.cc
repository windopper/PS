#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int INF = 500001;

struct Node {
    ll v;
    Node *l, *r;
    Node() {
        l = r = NULL;
        v = 0;
    }
};

Node* root[INF];
Node* cntRoot[INF];

void initCnt(int s, int e, Node* cur) {
    if(s == e) {
        cur->v = 0;
        return;
    }
    int m = (s+e) >> 1;
    initCnt(s, m, cur->l = new Node());
    initCnt(m+1, e, cur->r = new Node());
    cur->v = cur->l->v + cur->r->v;
}

void initRoot(int s, int e, Node* cur, ll v) {
    if(s == e) {
        cur->v = v;
    }
}

void cntAdd(int s, int e, Node* prv, Node* cur, int x) {
    if(s == e) {
        cur->v++;
        return;
    }
    int m = (s+e) >> 1;
    if(x <= m) {
        cur->l = new Node();
        cur->r = prv->r;
        cntAdd(s, m, prv->l, cur->l, x);
    }
    else {
        cur->r = new Node();
        cur->l = prv->l;
        cntAdd(m+1, e, prv->r, cur->r, x);
    }
    cur->v = cur->l->v + cur->r->v;
}

ll queryXOR(int s, int e, Node* l, Node* r, ll x) {
    if(s == e) return l->v ^ x;
    int m = (s + e) >> 1;
    return max(queryXOR(s, m, l->l, r->l, x), queryXOR(m+1, e, l->r, r->r, x));
}

ll queryCount(int s, int e, Node* l, Node* r, ll x) {
    if(x < s) return 0;
    if(e <= x) return l->v;
    int m = (s+e) >> 1;
    return queryCount(s, m, l->l, r->l, x) + queryCount(m+1, e, l->r, r->r, x);
}

ll queryKthSmall(int s, int e, Node* l, Node* r, ll x) {
    if(s == e) return s;
    int m = (s+e) >> 1;
    ll diff = r->l->v - l->l->v;
    if(x <= diff) {
        return queryKthSmall(s, m, l->l, r->l, x);
    }
    else return queryCount(m+1, e, l->r, r->r, x - diff);
}

int maxRight = 0;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int M;
    cin >> M;
    while(M--) {
        int a;
        cin >> a;
        if(a == 1) {
            ll x;
            cin >> x;
            maxRight++;
            cntAdd(1, INF-1, cntRoot[maxRight], cntRoot[maxRight + 1], x);
        }
        else if(a == 2) {
            int l, r;
            cin >> l >> r;
        }
        else if(a == 3) {
            int k;
            cin >> k;
            maxRight -= k;
        }
        else if(a == 4) {

        }
        else {

        }
    }
}