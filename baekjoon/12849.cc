#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> graph;
int dp[9][100001];
int D;
const int MOD = 1000000007;

void put(int a, int b) {
    graph[a].push_back(b);
}

int solve(int cur, int remain) {
    if(remain < 0) return 0;
    if(remain == 0 && cur == 0) return 1;
    int &ret = dp[cur][remain];
    if(ret != -1) return ret;
    ret = 0;
    for(int next : graph[cur]) {
        ret += solve(next, remain - 1);
        ret %= MOD;
    }
    return ret % MOD;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    graph.resize(9);
    put(0, 1);
    put(0, 2);
    put(1, 0);
    put(1, 2);
    put(1, 3);
    put(2, 0);
    put(2, 1);
    put(2, 3);
    put(2, 4);
    put(3, 1);
    put(3, 2);
    put(3, 4);
    put(3, 5);
    put(4, 2);
    put(4, 3);
    put(4, 5);
    put(4, 7);
    put(5, 3);
    put(5, 4);
    put(5, 6);
    put(6, 5);
    put(6, 7);
    put(7, 4);
    put(7, 6);

    memset(dp, -1, sizeof(dp));
    cin >> D;
    cout << solve(0, D) % MOD;
}