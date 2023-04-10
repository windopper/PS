#include <bits/stdc++.h>

using namespace std;

int tree[280000];
int arr[250001];

void update(int s, int e, int i, int ui, int ud) {
    if(s > ui || e < ui) return;
    if(s == e) {
        tree[i] += ud;
        return;
    }
    int m = (s+e)/2;
    update(s, m, i*2, ui, ud);
    update(m+1, e, i*2+1, ui, ud);
    tree[i] = tree[i*2] + tree[i*2+1];
}

int query(int s, int e, int i, int target) {
    if(s == e) return s;
    int m = (s+e)/2;    
    if(target <= tree[i*2]) {
        return query(s, m, i*2, target);
    }
    return query(m+1, e, i*2+1, target - tree[i*2]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, K;
    cin >> N >> K;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    int mid = (K+1)/2;
    int l = 0, r = 0;
    while(r < K-1) {
        update(0, 65535, 1, arr[r++], 1);
    }
    long long ans = 0;
    while(r < N) {
        update(0, 65535, 1, arr[r++], 1);
        ans += (long long)query(0, 65535, 1, mid);
        update(0, 65535, 1, arr[l++], -1);
    }
    cout << ans << '\n';
}