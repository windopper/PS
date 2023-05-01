#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int N;
struct Node { 
    int lval, rval, lvalc, rvalc, val, perf;
};
// L -> 0 R -> 1

bool arr[200001];
Node tree[800004];

Node f(Node& l, Node& r) {
    int lval, rval, lvalc, rvalc, val, perf;
    perf = 0;
    val = max(l.val, r.val);
    lval = l.lval;
    rval = r.rval;
    if(l.rvalc != r.lvalc) {
        int tmp = l.rval + r.lval;
        if(l.perf && r.perf) perf = 1;
        if(l.perf) lval = tmp;
        if(r.perf) rval = tmp;
        val = max(tmp, val);
    }
    return {lval, rval, l.lvalc, r.rvalc, val, perf};
}

void init(int s, int e, int i) {
    if(s == e) {
        tree[i] = {1, 1, arr[s], arr[s], 1, 1};
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
        tree[i] = {1, 1, arr[s], arr[s], 1, 1};
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