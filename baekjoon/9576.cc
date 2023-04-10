#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for(; T>0; --T) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> count(N+1);
        for(int i=1; i<M+1; i++) {
            int a, b;
            cin >> a >> b;
            for(int i=a; i<=b; ++i) count[i].push_back(i);
        }
    }
}