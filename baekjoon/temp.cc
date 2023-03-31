#include <bits/stdc++.h>

using namespace std;
int N, M;
map<int, int> ct;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) {
        int t;
        cin >> t;
        ++ct[t];
    }
    cin >> M;
    for(int i=0; i<M; i++) {
        int t;
        cin >> t;
        cout << ct[t] << " ";
    }
}