#include <bits/stdc++.h>

using namespace std;
int arr[2001];
int dp[2001][2001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> arr[i];
    }
    for(int i=1; i<=N; i++) dp[i][i] = 1;
    for(int i=1; i<=N-1; i++) if(arr[i] == arr[i+1]) dp[i][i+1] = 1;
    for(int i=2; i<=N-1; i++) {
        for(int l=1; l<=N-i; l++) {
            int r = l + i;
            if(arr[l] == arr[r] && dp[l+1][r-1]) dp[l][r] = 1;
        }
    }
    int M;
    cin >> M;
    while(M--) {
        int l, r;
        cin >> l >> r;
        cout << dp[l][r] << '\n';
    }
}