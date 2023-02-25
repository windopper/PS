#include <bits/stdc++.h>
#include <limits>

using namespace std;
#define MAX 10000001
int N;
vector<vector<int>> arr;
int minValue = MAX;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;

    for(int i=1; i<N+1; i++) {
        vector<int> vec(3);
        for(int j=0; j<3; j++) cin >> vec[j];
        arr.push_back(vec);
    }
    for(int i=0; i<3; i++) {
        int dp[N+1][3];
        for(int j=0; j<3; j++) {
            if(i==j) dp[1][i] = arr[0][i];
            else dp[1][j] = MAX;
        }
        for (int k = 2; k < N + 1; k++) {
            dp[k][0] = min(dp[k-1][1],dp[k-1][2])+arr[k-1][0];
            dp[k][1] = min(dp[k-1][0],dp[k-1][2])+arr[k-1][1];
            dp[k][2] = min(dp[k-1][1],dp[k-1][0])+arr[k-1][2];
        }
        for (int l = 0; l < 3; l++) {
            if(l==i) continue;
            minValue = min(dp[N][l], minValue);
        }
    }

    cout << minValue;
}
