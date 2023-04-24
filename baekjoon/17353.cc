#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N;

const int INF = 100001;
vector<int> arr;
ll tree[INF*4];
vector<pair<int, int>> lazy[INF*4];

void init(int s, int e, int i) {
    if(s == e) {
        tree[i] = arr[s];
        return;
    }
    int m = (s+e)/2;
    init(s, m, i*2);
    init(m+1, e, i*2+1);
    tree[i] = tree[i*2] + tree[i*2+1];
}

ll cal(int s, int e, int l, int r) {
    ll ret = 0;
    for(int i=l; i<=r; ++i) {
        if(i >= s && i <= e) ret += i-l+1; 
    }
    return ret;
}

void propagate(int s, int e, int i) {
    if(!lazy[i].empty()) {
        if(s != e) {
            for(pii cur : lazy[i]) {
                int l = cur.first;
                int r = cur.second;
                lazy[i*2].push_back({l, r});
                lazy[i*2+1].push_back({l, r});
            }
        }
        for(pii cur : lazy[i]) {
            tree[i] += cal(s, e, cur.first, cur.second);
        }
        lazy[i].clear();
    }
}

void update(int s, int e, int i, int l, int r) {
    propagate(s, e, i);
    if(s > r || e < l) return;
    if(s >= l && e <= r) {
        lazy[i].push_back({l, r});
        propagate(s, e, i);
        return;
    }
    int m = (s+e)/2;
    update(s, m, i*2, l, r);
    update(m+1, e, i*2+1, l, r);
    tree[i] = tree[i*2] + tree[i*2+1];
}

ll query(int s, int e, int i, int t) {
    propagate(s, e, i);
    if(s > t || e < t) return 0;
    if(s == e) return tree[i];
    int m = (s+e)/2;
    return query(s, m, i*2, t) + query(m+1, e, i*2+1, t);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    arr.resize(N+1);
    for(int i=1; i<=N; i++) {
        cin >> arr[i];
    }
    init(1, N, 1);

    int Q;
    cin >> Q;
    while(Q--) {
        int a;
        cin >> a;
        if(a == 1) {
            int l, r;
            cin >> l >> r;
            update(1, N, 1, l, r);
        }
        else {
            int x;
            cin >> x;
            cout << query(1, N, 1, x) << '\n';
        }
    }
}