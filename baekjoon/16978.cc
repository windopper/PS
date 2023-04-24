#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;

long long tree[1 << 18] = {0, };
int base = 1 << 17;

bool compare(vi& a, vi& b) {
    return a[0] < b[0];
}

void update(int x, long long v) {
    x |= base;
    tree[x] = v;
    while(x >>= 1) {
        tree[x] = tree[x << 1] + tree[x << 1 | 1];
    }
}

long long query(int a, int b) {
    a |= base;
    b |= base;
    long long ret = 0;
    while(a <= b) {
        if(a & 1) ret += tree[a++];
        if(~b & 1) ret += tree[b--];
        a >>= 1, b >>= 1;
    }
    return ret;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    for(int i=1; i<=N; i++) {
        int t;
        cin >> t;
        update(i, t);
    }
    int M;
    cin >> M;
    vector<pair<int, int>> updates;
    vector<vector<int>> queries;
    int qCnt = 0;
    for(int i=0; i<M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1) {
            updates.push_back({b, c});
        }
        else {
            int d;
            cin >> d;
            queries.push_back({b, c, d, qCnt++});
        }
    }
    sort(queries.begin(), queries.end(), compare);
    int cur = 0;
    vector<long long> result(queries.size());
    for(vi q : queries) {
        int seq = q[0];
        while(seq > cur) {
            pii u = updates[cur];
            update(u.first, u.second);
            ++cur;
        }
        result[q[3]] = query(q[1], q[2]);
    }

    for(long long ans : result) {
        cout << ans << '\n';
    }
}