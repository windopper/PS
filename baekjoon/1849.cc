#include <bits/stdc++.h>

using namespace std;
int tree[400000] = {0, };

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

int query(int s, int e, int i, int target) {
    --tree[i];
    if(s == e) return s;
    int m = (s+e)/2;
    if(target < tree[i*2]) {
        return query(s, m, i*2, target);
    }
    else return query(m+1, e, i*2+1, target - tree[i*2]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    init(1, N, 1);
    vector<int> arr(N+1);
    for(int i=1; i<N+1; i++) {
        int t;
        cin >> t;
        int idx = query(1, N, 1, t);
        arr[idx] = i;
    }

    for(int i=1; i<N+1; i++) cout << arr[i] << '\n';
}