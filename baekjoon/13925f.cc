#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const long long MOD = 1000000007;

int N;
ll tree[100001];
pair<ll, ll> lazy[100001];
// {0, 1}
// add, mul

void propagation(int s, int e, int i) {
    if(lazy[i].first != 0 || lazy[i].second != 1) {
        if(s != e) {
            lazy[i*2].first = (lazy[i].first + lazy[i*2].first * lazy[i].second) % MOD;
            lazy[i*2].second = (lazy[i].second * lazy[i*2].second) % MOD;
            lazy[i*2+1].first = (lazy[i].first + lazy[i*2+1].first * lazy[i].second) % MOD;
            lazy[i*2+1].second = (lazy[i].second * lazy[i*2+1].second) % MOD;
        }

        tree[i] = ((lazy[i].second * tree[i]) % MOD + ((e-s+1) * lazy[i].first) % MOD) % MOD;
        lazy[i] = {0, 1};
    }
}

long long sum(int i) {
    int ans = 0;
    while ( i > 0 ) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}

long long sum(int i, int j) {
    return sum(j) - sum(i-1);
}

void update(int i, int diff) {
    while ( i < 100001 ) {
        tree[i] += diff;
        i += (i & -i);
    }
}


void updateChange(int s, int e, int i, int l, int r, long long v) {
    propagation(s, e, i);
    if(s > r || e < l) return;
    if(s >= l && e <= r) {
        lazy[i] = {v, 0};
        propagation(s, e, i);
        return;
    }
    int m = (s+e) / 2;
    updateChange(s, m, i*2, l, r, v);
    updateChange(m+1, e, i*2+1, l, r, v);
    tree[i] = (tree[i*2] + tree[i*2+1]) % MOD;
}

void updateSum(int s, int e, int i, int l, int r, long long v) {
    propagation(s, e, i);
    if(s > r || e < l) return;
    if(s >= l && e <= r) {
        lazy[i] = {(lazy[i].first + v) % MOD, lazy[i].second};
        propagation(s, e, i);
        return;
    }
    int m = (s+e) / 2;
    updateSum(s, m, i*2, l, r, v);
    updateSum(m+1, e, i*2+1, l, r, v);
    tree[i] = (tree[i*2] + tree[i*2+1]) % MOD;
}

void updateMul(int s, int e, int i, int l, int r, long long v) {
    propagation(s, e, i);
    if(s > r || e < l) return;
    if(s >= l && e <= r) {
        lazy[i] = {(lazy[i].first * v) % MOD, (lazy[i].second * v) % MOD};
        propagation(s, e, i);
        return;
    }
    int m = (s+e) / 2;
    updateMul(s, m, i*2, l, r, v);
    updateMul(m+1, e, i*2+1, l, r, v);
    tree[i] = (tree[i*2] + tree[i*2+1]) % MOD;
}

int find(int s, int e, int i, int l, int r) {
    propagation(s, e, i);
    if(s > r || e < l) return 0;
    if(s >= l && e <= r) {
        return tree[i] % MOD;
    }
    int m = (s+e)/2;
    return (find(s, m, i*2, l, r) + find(m+1, e, i*2+1, l, r)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<400004; i++) {
        lazy[i] = {0, 1};
    }
    for(int i=0; i<N; i++) {
        long long tmp;
        cin >> tmp;
        tmp %= MOD;
        updateChange(1, N, 1, i+1, i+1, tmp);
    }

    int M;
    cin >> M;
    for(int i=0; i<M; i++) {
        long long c, x, y, v;
        cin >> c >> x >> y;
        if(c == 1) {
            cin >> v;
            v %= MOD;
            updateSum(1, N, 1, x, y, v);
        }
        else if(c == 2) {
            cin >> v;
            v %= MOD;
            updateMul(1, N, 1, x, y, v);
        }
        else if(c == 3) {
            cin >> v;
            v %= MOD;
            updateChange(1, N, 1, x, y, v);
        }
        else {
            cout << find(1, N, 1, x, y) << "\n";
        }
    }
}