#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int N;
struct Node { 
    int lval, rval, val, lvalll, lvalrr, rvalll, rvalrr, valll, valrr;
};
// L -> 0 R -> 1

Node tree[808080];
int base = 1 << 19;
bool arr[200001] = {0, };

Node f(Node& l, Node& r) {
    int lval, rval, val, lvalll, lvalrr, rvalll, rvalrr, valll, valrr;

    if(l.lvalrr + 1 == r.lvalll && arr[l.lvalrr] != arr[r.lvalll] && l.lval <= l.lval + r.lval) {
        lval = l.lval + r.lval;
        lvalll = l.lvalll;
        lvalrr = r.lvalrr;
    }
    else {
        lval = l.lval;
        lvalll = l.lvalll;
        lvalrr = l.lvalrr;
    }
    
    if(l.rvalrr + 1 == r.rvalll && arr[l.rvalrr] != arr[r.rvalll] && r.rval <= r.rval + l.rval) {
        rval = r.rval + l.rval;
        rvalll = l.rvalll;
        rvalrr = r.rvalrr;
    }
    else {
        rval = r.rval;
        rvalll = r.rvalll;
        rvalrr = r.rvalrr;
    }

    int t1 = l.rval + r.lval;
    int t2 = l.val;
    int t3 = r.val;

    if(arr[l.rvalrr] != arr[r.lvalll] && t2 <= t1 && t3 <= t1) {
        val = l.rval + r.lval;
        valll = l.rvalll;
        valrr = r.lvalrr;
    }
    else if(t1 <= t3 && t2 <= t3) {
        val = r.val;
        valll = r.valll;
        valrr = r.valrr;
    }
    else {
        val = l.val;
        valll = l.valll;
        valrr = l.valrr;
    }
    //cout << val <<" ";
    return {lval, rval, val, lvalll, lvalrr, rvalll, rvalrr, valll, valrr};
}

void update(int i) {
    arr[i] ^= 1;
    int x = i;
    i |= base;
    tree[i] = {1, 1, 1, x, x, x, x, x, x};
    while(i >>= 1) {
        tree[i] = f(tree[i << 1] , tree[i << 1 | 1]);
    }
}

void init(int s, int e, int i) {
    if(s == e) {
        tree[i] = {1, 1, 1, s, s, s, s, s, s};
        return;
    }
    int m = (s+e) >> 1;
    init(s, m, i*2);
    init(m+1, e, i*2+1);
    tree[i] = f(tree[i << 1] , tree[i << 1 | 1]);
}

void update(int s, int e, int i, int ui) {
    if(s > ui || e < ui) return;
    if(s == e) {
        arr[s] ^= 1;
        tree[i] = {1, 1, 1, s, s, s, s, s, s};
        return;
    }
    int m = (s+e) >> 1;
    update(s, m, i*2, ui);
    update(m+1, e, i*2+1, ui);
    tree[i] = f(tree[i << 1] , tree[i << 1 | 1]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, Q;
    cin >> N >> Q;
    init(1, N, 1);
    while(Q--) {
        int t;
        cin >> t;
        update(1, N, 1, t);
        cout << tree[1].val << '\n';
    }
}