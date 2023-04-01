#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M, K;
    cin >> N >> M >> K;
    for(; K>0; --K) {
        if(N >= 2 * M) --N;
        else --M;
    }

    if(N >= 2 * M) cout << M;
    else cout << N / 2;
}