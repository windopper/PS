#include <bits/stdc++.h>

using namespace std;
const int INF = 500001;
int N;
int arr[INF];
int tree[INF*4] = {0, };
int lazy[INF*4] = {0, };

void propagate(int s, int e, int i) {
    if(lazy[i]) {
        if(s != e) {
            lazy[i*2] ^= lazy[i];
            lazy[i*2+1] ^= lazy[i];
        }
        tree[i] ^= lazy[i];
        lazy[i] = 0;
    }
}

void init(int s, int e, int i) {
    if(s == e) {
        tree[i] = arr[s];
        return;
    }
    int m = (s+e) >> 1;
    init(s, m, i*2);
    init(m+1, e, i*2+1);
}

void update(int s, int e, int i, int l, int r, int ud) {
    propagate(s, e, i);
    if(s > r || e < l) return;
    if(s >= l && e <= r) {
        lazy[i] ^= ud;
        propagate(s, e, i);
        return;
    }
    int m = (s+e) >> 1;
    update(s, m, i*2, l, r, ud);
    update(m+1, e, i*2+1, l, r, ud);
}

int query(int s, int e, int i, int ui) {
    propagate(s, e, i);
    if(s > ui || e < ui) return 0;
    if(s == e) return tree[i];
    int m = (s+e) >> 1;
    return max(query(s, m, i*2, ui), query(m+1, e, i*2+1, ui));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[i];
    init(1, N, 1);
    // nlogn
    int M;
    cin >> M;

    while(M--) {
        int t;
        cin >> t;
        if(t == 1) {
            int a, b, c;
            cin >> a >> b >> c;
            update(1, N, 1, a+1, b+1, c);
        }
        else {
            int a;
            cin >> a;
            cout << query(1, N, 1, a+1) << '\n';
        }
    }
}