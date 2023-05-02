#include <bits/stdc++.h>

using namespace std;
int N, M;
int const INF = 987654321;
vector<vector<int>> arr;
vector<vector<int>> vis;
int dx[3] = {0, 1, -1};
int dy[3] = {1, 0, 0};

int dp[1001][1001][3];

int solve(int x, int y, int dir) {
    if(x == M-1 && y == N-1) return 0;
    int &ret = dp[y][x][dir];
    if(ret != -1) return ret;
    ret = -INF;
    for(int i=0; i<3; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0||nx>=M||ny<0||ny>=N) continue;
        if(vis[ny][nx]) continue;
        vis[ny][nx] = 1;
        ret = max(ret, solve(nx, ny, i) + arr[ny][nx]);
        vis[ny][nx] = 0;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    arr.resize(N, vector<int>(M));
    vis.assign(N, vector<int>(M, 0));
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> arr[i][j];
        }
    }
    vis[0][0] = 1;
    cout << solve(0, 0, 0) + arr[0][0];
}