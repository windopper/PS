#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> matrix(N, vector<int>(M, 0));
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            int t; cin >> t;
            matrix[i][j] += t;
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            int t; cin >> t;
            matrix[i][j] += t;
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << '\n';
    }
}