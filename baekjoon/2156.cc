#include <bits/stdc++.h>

using namespace std;
int n;
int arr[10001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int dp[n+1][3];
    for(int i=1; i<n+1; i++) cin >> arr[i];
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<3; j++) dp[i][j] = 0;
    }

    int ans = 0;

    for(int i=1; i<n+1; i++) {
        int tmp = max(dp[i-1][0], dp[i-1][1]);
        dp[i][0] = max(tmp, dp[i-1][2]);
        dp[i][1] = dp[i-1][0] + arr[i];
        dp[i][2] = dp[i-1][1] + arr[i];
        tmp = max(dp[i][0], dp[i][1]);
        tmp = max(tmp, dp[i][2]);
        ans = max(ans, tmp);
    } 

    cout << ans;
}