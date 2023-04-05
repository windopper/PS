#include <bits/stdc++.h>

using namespace std;

int dp[501][501];

int solve(vector<vector<int>>& t, int x, int y) {
    if(y >= t.size()) return 0;
    int &ret = dp[y][x];
    if(ret != -1) return ret;
    ret = max(ret, solve(t, x, y+1) + t[y][x]);
    ret = max(ret, solve(t, x+1, y+1) + t[y][x]);
    return ret;
}

int solution(vector<vector<int>> triangle) {
    memset(dp, -1, sizeof(dp));
    return solve(triangle, 0, 0);
}