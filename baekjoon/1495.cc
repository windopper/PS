#include <bits/stdc++.h>

using namespace std;
int N, S, M;
int arr[51];
bool dp[1001][51];

void solve(int cur, int idx) {

    dp[cur][idx] = true;
    if(idx == N) {
        return;
    }

    if(cur + arr[idx] <= M && !dp[cur + arr[idx]][idx + 1]) {
        solve(cur + arr[idx], idx + 1);
    }
    if(cur - arr[idx] >= 0 && !dp[cur - arr[idx]][idx + 1]) {
        solve(cur - arr[idx], idx + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> S >> M;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }

    solve(S, 0);
    
    for(int i=M; i>=0; --i) {
        if(dp[i][N]) {
            cout << i;
            return 0;
        }
    }

    cout << -1;
    
}