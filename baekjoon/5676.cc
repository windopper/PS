#include <bits/stdc++.h>

using namespace std;

int arr[100001];
int tree[400004];

void init(int s, int e, int i) {
    if(s == e) {
        if(arr[s] > 0) tree[i] = 1;
        else if(arr[s] < 0) tree[i] = -1;
        else tree[i] = 0;
        return;
    }
    int m = (s+e) / 2;
    init(s, m, i*2);
    init(m+1, e, i*2+1);
    tree[i] = tree[i*2] * tree[i*2+1];
}

void update(int s, int e, int i, int ui, int ud) {
    if(s > ui || e < ui) return;
    if(s == e) {
        tree[i] = ud;
        return;
    }
    int m = (s+e) / 2;
    update(s, m, i*2, ui, ud);
    update(m+1, e, i*2+1, ui, ud);
    tree[i] = tree[i*2] * tree[i*2+1];
}

int query(int s, int e, int i, int l, int r) {
    if(s > r || e < l) return 1;
    if(l <= s && e <= r) return tree[i];
    int m = (s+e)/2;
    return query(s, m, i*2, l, r) * query(m+1, e, i*2+1, l, r);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, K;
    while(cin >> N >> K) {
        memset(tree, -1, sizeof(tree));
        for(int i=1; i<N+1; i++) cin >> arr[i];
        init(1, N, 1);

        for(int i=0; i<K; i++) {
            char c;
            int a, b;
            cin >> c >> a >> b;

            if(c == 'C') {
                if(b>0) b = 1;
                else if(b<0) b = -1;
                else b = 0;
                update(1, N, 1, a, b);
            }
            else if(c == 'P') {
                int ans = query(1, N, 1, a, b);
                if(ans == -1) cout << '-';
                else if(ans == 1) cout << '+';
                else cout << 0;
            }
        }

        cout << '\n';
    }
}