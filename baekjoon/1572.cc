#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll arr[250001];
vector<ll> tree[1000001];

void init(int s, int e, int i) {
    vector<int>& cur = tree[i];
    if(s == e) {
        cur.push_back(arr[s-1]);
        return;
    }
    int m = (s+e)/2;
    init(s, m, i*2);
    init(m+1, e, i*2+1);
    vector<int>& l = tree[i*2], &r = tree[i*2+1];
    merge(l.begin(), l.end(), r.begin(), r.end(), cur.begin());
}

long long query(int s, int e, int i, int l, int r) {
    if(s > r || e < l) return 0;
    if(s >= l && e <= r) {
        return tree[i][tree[i].size() + 1 / 2];
    }

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, K;
    cin >> N >> K;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }

    init(1, N, 1);
}