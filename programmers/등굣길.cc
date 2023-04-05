#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> p;
const int MOD = 1000000007;
int dp[101][101];
int M, N;

int solve(int x, int y) {
    if(x == M-1 && y == N-1) return 1;
    int &ret = dp[y][x];
    if(ret != -1) return ret;
    ret = 0;
    if(x+1 <= M-1 && p[y][x+1] == 0) {
        ret += solve(x+1, y);
        ret %= MOD;
    }
    if(y+1 <= N-1 && p[y+1][x] == 0) {
        ret += solve(x, y+1);
        ret %= MOD;
    }
    return ret;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    p.assign(n, vector<int>(m, 0));
    for(int i=0; i<puddles.size(); i++) {
        p[puddles[i][1]-1][puddles[i][0]-1] = 1;
    }
    M = m;
    N = n;
    memset(dp, -1, sizeof(dp));
    return solve(0, 0);
}