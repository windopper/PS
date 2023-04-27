#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 4587521;
ll changedProp = 0;

pair<ll, ll> tree[MAXN*4];
// max min
ll lazy[MAXN*4];
int C, N, O;

ll toAdd(pair<ll, ll> pll, ll toAdd) {
    ll ret = toAdd;
    if(pll.second + toAdd < 0) ret = -pll.second;
    else if(pll.first + toAdd > N) ret = N - pll.first;
    return ret;
}

void propagate(int s, int e, int i) {
    if(lazy[i] != 0) {
        tree[i].first += lazy[i];
        tree[i].second += lazy[i];
        if(s != e) {
            lazy[i*2] += lazy[i];
            lazy[i*2+1] += lazy[i];
        }
        lazy[i] = 0;
    }
}

void update(int s, int e, int i, int l, int r, ll v) {
    propagate(s, e, i);
    if(s > r || e < l) return;
    if(s >= l && e <= r) {
        lazy[i] += v;
        propagate(s, e, i);
        return;
    }
    int m = (s+e)/2;
    update(s, m, i*2, l, r, v);
    update(m+1, e, i*2+1, l, r, v);
    tree[i].first = max(tree[i*2].first, tree[i*2+1].first);
    tree[i].second = min(tree[i*2].second, tree[i*2+1].second);
}

void updateIndividual(int s, int e, int i, int ui, ll ud) {
    propagate(s, e, i);
    if(s > ui || e < ui) return;
    if(s == e) {
        lazy[i] += ud;
        propagate(s, e, i);
        return;
    }
    int m = (s+e)/2;
    updateIndividual(s, m, i*2, ui, ud);
    updateIndividual(m+1, e, i*2+1, ui, ud);
    pair<ll, ll> t1 = tree[i*2];
    pair<ll, ll> t2 = tree[i*2+1];
    tree[i] = {max(t1.first, t2.first), min(t1.second, t2.second)};
}

pair<ll, ll> query(int s, int e, int i, int l, int r) {
    propagate(s, e, i);
    if(s > r || e < l) return {-10001, 10001};
    if(s >= l && e <= r) return tree[i];
    int m = (s+e)/2;
    pair<ll, ll> t1 = query(s, m, i*2, l, r);
    pair<ll, ll> t2 = query(m+1, e, i*2+1, l, r);
    return {max(t1.first, t2.first), min(t1.second, t2.second)};
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> C >> N >> O;
    while(O--) {
        string s;
        ll v;
        cin >> s >> v;
        ++v;
        if(s == "state") {
            cout << query(1, C, 1, v, v).second << '\n';
        }
        else if(s == "groupchange") {
            ll j, k;
            cin >> j >> k;
            ++j;
            ll w = toAdd(query(1, C, 1, v, j), k);
            update(1, C, 1, v, j, w);
            cout << w << "\n";
        }
        else {
           ll j;
           cin >> j;
           ll w = toAdd(query(1, C, 1, v, v), j);
           updateIndividual(1, C, 1, v, w);
           cout << w << '\n';
        }
    }
}