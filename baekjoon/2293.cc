#include <iostream>

using namespace std;
int n, k;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    int coins[n];
    int dp[k+1];
    for(int i=0; i<n; i++) {
        cin >> coins[i];
    }
    for (int j = 0; j < k + 1; j++)
    {
        dp[j] = 0;
    }

    for(int i=1; i<n+1; i++) {
        for(int j=coins[i-1]; j<k+1; j++) {
            if( j == coins[i-1] ) {
                dp[j] = dp[j] + 1;
                continue;
            }
            dp[j] = dp[j-coins[i-1]] + dp[j];
        }
    }  

    cout << dp[k];
}