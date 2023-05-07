#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long int ulli;
const ulli MOD = 1000000007;
ulli N, x0, a, b;

ulli create(int lim) {
    ulli ret = x0;
    for(int i=1; i<=lim; i++) {
        ret = ((ret * a) % MOD + b) % MOD;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> x0 >> a >> b;
    int Q;
    cin >> Q;
    vector<int> queries(Q);
    ulli ans = 0;
    for(int i=0; i<Q; i++) {
        cin >> queries[i];
        ans += create(queries[i]);
    }
    cout << ans;
}