#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string a, b;
    cin >> a >> b;
    int dp[4001][4001];
    dp[0][0] = 0;
    int maxValue = 0;
    for(int i=0; i<a.size(); i++) {
        for(int j=0; j<b.size(); j++) {
            if(a[i] != b[j]) continue;
            if(i==0 || j==0) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j-1] + 1;
            maxValue = max(maxValue, dp[i][j]);
        }
    }
    cout << maxValue;
}