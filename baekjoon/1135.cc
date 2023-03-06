#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj;
int dp[51] = {0, };

int dfs(int x) {
    if(dp[x] != 0) return dp[x];
    int res = 0;
    vector<int> arr;
    for(int i : adj[x]) {
        arr.push_back(dfs(i));
    }
    sort(arr.begin(), arr.end(), greater<>());
    int inc = 1;
    for(int i : arr) {
        res = max(res, i + inc++);
    }
    return dp[x] = res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    adj.resize(N+1);
    for(int i=0; i<N; i++) {
        int temp; cin >> temp;
        dp[i] = 0;
        if(temp == -1) continue;
        adj[temp].push_back(i);
    }
    dfs(0);
    cout << dp[0];
}