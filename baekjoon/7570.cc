#include <bits/stdc++.h>

using namespace std;

int N;
int arr[1000001];
int dp[1000001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    int ans = 0;
    for(int i=1; i<N+1; i++) {
        cin >> arr[i];
        dp[arr[i]] = dp[arr[i]-1] + 1;
        ans = max(ans, dp[arr[i]]);
    }

    cout << N - ans;
}