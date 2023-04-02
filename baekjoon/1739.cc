#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for(; T>=0; --T) {
        int N, M, K;
        adj.assign(N*M+2, vector<int>());
        for(int i=0; i<K; i++) {
            int A, B, C, D, A_, B_, C_, D_;
            cin >> A >> B >> C >> D;
            int t1 = C + (B-1) * N;
            int t2 = A + (D-1) * N;
            if(A<C && B<D) {
                adj[t1*2]
            }
        }
    }
}