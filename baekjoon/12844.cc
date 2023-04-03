#include <bits/stdc++.h>

using namespace std;
int tree[2000000];
int lazy[2000000];
int arr[500000];

void propagate(int s, int e, int i) {
    if(lazy[i]) {
        if((e-s+1) % 2 == 1) {
            tree[i] ^= lazy[i];
        }
        if(s != e) {
            lazy[i*2] = lazy[i*2] ^ lazy[i];
            lazy[i*2+1] = lazy[i*2+1] ^ lazy[i];
        }
        lazy[i] = 0;
    }
}

void init(int s, int e, int i) {
    if(s == e) {
        tree[i] = arr[s-1];
        return;
    }
    int m =(s+e)/2;
    init(s, m, i*2);
    init(m+1, e, i*2+1);
    tree[i] = tree[i*2] ^ tree[i*2+1];
}

void update(int s, int e, int i, int l, int r, int d) {
    propagate(s, e, i);
    if(s > r || e < l) return;
    if(s >= l && e <= r) {
        lazy[i] = d;
        propagate(s, e, i);
        return;
    }
    int m = (s+e)/2;
    update(s, m, i*2, l, r, d);
    update(m+1, e, i*2+1, l, r, d);
    tree[i] = tree[i*2] ^ tree[i*2+1];
}

int query(int s, int e, int i, int l, int r) {
    propagate(s, e, i);
    if(s > r || e < l) return 0;
    if(s >= l && e <= r) {
        return tree[i];
    }
    int m = (s+e)/2;
    return query(s, m, i*2, l, r) ^ query(m+1, e, i*2+1, l, r);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }

    init(1, N, 1);

    int M;
    cin >> M;
    for(int i=0; i<M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1) {
            int d; cin >> d;
            update(1, N, 1, b+1, c+1, d);
        }
        else {
            cout << query(1, N, 1, b+1, c+1) << "\n";
        }
    }
}