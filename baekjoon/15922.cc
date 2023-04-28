#include <bits/stdc++.h>

using namespace std;

const long long INF = 1000000000;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    long long l = -INF, r = -INF;
    long long res = 0;
    for(int i=0; i<N; i++) {
        long long x, y;
        cin >> x >> y;
        if(r <= x) {
            res += r-l;
            l = x;
            r = y;
        }
        else if(l <= x && x <= r) {
            r = max(r, y);
        }
    }
    res += r-l;

    cout << res;
}