#include <bits/stdc++.h>

using namespace std;

int tree[400000];

void init(int s, int e, int i) {
    if(s == e) {
        tree[i] = 1;
        return;
    }
    int m = (s+e)/2;
    init(s, m, i*2);
    init(m+1, e, i*2+1);
    tree[i] = tree[i*2] + tree[i*2+1];
}

void update(int s, int e, int i, int ui) {
    if(s > ui || e < ui) return;
    if(s == e) {
        tree[i] = 0;
        return;
    }
    int m = (s+e)/2;
    update(s, m, i*2, ui);
    update(m+1, e, i*2+1, ui);
    tree[i] = tree[i*2] + tree[i*2+1];
}

int query(int s, int e, int i, int l, int r) {
    if(s > r || e < l) return 0;
    if(s >= l && e <= r) return tree[i];
    int m = (s+e)/2;
    return query(s, m, i*2, l, r) + query(m+1, e, i*2+1, l, r);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for(; T>0; --T) {
        int N;
        cin >> N;
        vector<int> arr(N+1);
        init(1, N, 1);
        for(int i=1; i<N+1; i++) {
            int t;
            cin >> t;
            arr[t] = i;
        }

        int ans = 0;
        for(int i=1; i<N+1; i++) {
            int t;
            cin >> t;
            int ret = query(1, N, 1, 1, arr[t]-1);
            ans += ret;
            update(1, N, 1, arr[t]);
        }
        cout << ans << '\n';
    }
}