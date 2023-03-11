#include <bits/stdc++.h>

using namespace std;
int N, M, p;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for(; T>0; --T) {
        cin >> N >> M;
        for(int i=0; i<M; i++) cin >> p >> p;
        cout << N-1 << "\n";
    }
}