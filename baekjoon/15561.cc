#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;
int N, Q, U, V;

struct Node {
    int lval, rval, mxval, all, ans, j, i;
    Node(int i, int j) {
        lval = rval = mxval = all = ans = -INF;
        this->j = j, this->i = i;
    }
    void set(int v) {
        lval = rval = mxval = all = v;
        ans = U * mxval + V * (j-i);
    }
};

Node* tree[400004];
int arr[100001];

Node* f(Node* l, Node* r) {
    Node* res = new Node(l->i, r->j);
}

void init(int s, int e, int i) {
    if(s == e) {
        tree[i] = new Node(s, e);
        tree[i]->set(arr[s]);
        return;
    }
    int m = (s+e) >> 1;
    init(s, m, i*2);
    init(m+1, e, i*2+1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> Q >> U >> V;
    for(int i=1; i<=N; i++) {
        int t; cin >> t;
    }
}