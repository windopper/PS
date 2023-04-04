#include <bits/stdc++.h>

using namespace std;
int N;
int dp[1001][1001];
int arr[1001];

int solve(int cur, int k) {
    if(k == N) return 0;
    int &ret = dp[cur][k];
    if(ret != -1) return ret;
    ret = 0;
    for(int i=k; i<N; i++) {
        if(arr[i] > cur) {
            ret = max(ret, solve(arr[i], i+1)+1);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    cout << solve(0, 0);
}