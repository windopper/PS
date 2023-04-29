#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 100001;

struct Node {
    ll mx, mn, mxcnt, sum;
};

Node tree[4*INF];
ll arr[INF];

void propagate(int s, int e, int i) {
    if(s == e) return;
    for(int next : {i*2, i*2+1}) {
        if(tree[next].mx > tree[i].mx) {
            
        }
    }
}

void update(int s, int e, int i, int l, int r) {
    propagate(s, e, i);
    if(s > r || e < l) return;
    if(s >= l && e <= r) {
        if(tree[i].mx == tree[i].mn) {
            ll to = floor(sqrt(tree[i].mx));
            tree[i].sum -= (tree[i].mx - to) * (e-s+1);
            tree[i].mx = to;
            tree[i].mn = to;
        }
        else if(tree[i].mx > tree[i].mn) {
            ll mxto = floor(sqrt(tree[i].mx));
            ll mnto = floor(sqrt(tree[i].mn));
            tree[i].sum -= (tree[i].mx - mxto) * tree[i].mxcnt;
            tree[i].mx = mxto;
            tree[i].mn = mnto;
        }
        propagate(s, e, i);
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[i];

}