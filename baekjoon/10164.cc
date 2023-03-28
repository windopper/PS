#include <bits/stdc++.h>

using namespace std;
int N, M, K;
vector<vector<int>> dp;

int solve(int x, int y, int tx, int ty) {
    if(x > tx || y > ty) return 0;
    if(x == tx && y == ty) {
        return 1;
    }
    int &ret = dp[y][x];
    if(ret != -1) return ret;
    ret = solve(x+1, y, tx, ty) + solve(x, y+1, tx, ty);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
    dp.assign(N+1, vector<int>(M+1, -1));
    int tx = (K-1) % M + 1;
    int ty = (K-1) / M + 1;
    if(K == 0) {
        tx = 1; 
        ty = 1;
    }
    if(tx == 0) tx = M;
    cout << solve(1, 1, tx, ty) * solve(tx, ty, M, N);
}