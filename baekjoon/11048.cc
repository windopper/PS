#include <bits/stdc++.h>

using namespace std;
int arr[1001][1001];
int dp[1001][1001];
int dx[3] = {0, 1, 1};
int dy[3] = {1, 0, 1};
int N, M;

int dfs(int x, int y) {
    if(x == M && y == N) {
        return arr[y][x];
    }
    int &ret = dp[y][x];
    if(ret != -1) return ret;

    for(int i=0; i<3; i++) {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if(nx<1 || nx>=M+1 || ny<1 || ny>=N+1) continue;
        ret = max(ret, dfs(nx, ny) + arr[y][x]);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    memset(dp, -1, sizeof(dp));
    for(int i=1; i<N+1; i++) {
        for(int j=1; j<M+1; j++) {
            cin >> arr[i][j];
        }
    }

    cout << dfs(1, 1);
}