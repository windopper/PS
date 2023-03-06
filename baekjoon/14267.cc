#include <bits/stdc++.h>

using namespace std;
const int MAX = 1000001;
int dist[MAX] = {0, };
int nxt[MAX];
int dp[MAX] = {0, };

int dfs(int cur) {
    if(cur == -1) return 0;
    if(dp[cur] != 0) return dp[cur];
    return dp[cur] = dfs(nxt[cur]) + dist[cur];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=1; i<n+1; i++) {
        int tmp; cin >> tmp;
        nxt[i] = tmp;
    }
    for(int i=0; i<m; i++) {
        int cur, w;
        cin >> cur >> w;
        dist[cur] += w;
    }
    for(int i=1; i<n+1; i++) {
        cout << dfs(i) << " ";
    }
}