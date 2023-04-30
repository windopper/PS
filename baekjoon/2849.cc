#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int N;
struct Node { 
    int lval, rval, val, lvalll, lvalrr, rvalll, rvalrr, valll, valrr;
};
// L -> 0 R -> 1

Node tree[1 << 18];
int base = 1 << 17;
bool arr[200001];

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
    int x = i;
    i |= base;
    tree[i] = {1, 1, 1, x, x, x, x, x, x};
    while(i >>= 1) {
        tree[i] = f(tree[i << 1] , tree[i << 1 | 1]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, Q;
    cin >> N >> Q;
    memset(arr, false, sizeof(arr));
    for(int i=1; i<=N; i++) update(i);
    while(Q--) {
        int t;
        cin >> t;
        arr[t] = arr[t] ? false : true;
        update(t);
        cout << tree[1].val << '\n';
    }
}