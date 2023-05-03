#include <bits/stdc++.h>

using namespace std;
int N, M;
vector<vector<char>> arr;
vector<vector<int>> vis;
vector<vector<int>> finished;
int dp[51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool hasCycle(int x, int y) {
    if(vis[y][x]) {
        //cout << x << " " << y << '\n';
        return true;
    }
    if(finished[y][x]) return false;
    vis[y][x] = 1;
    finished[y][x] = 1;
    for(int i=0; i<4; i++) {
        int nx = x + dx[i] * (arr[y][x] - '0');
        int ny = y + dy[i] * (arr[y][x] - '0');
        if(nx<0||nx>=M||ny<0||ny>=N || arr[ny][nx] == 'H') continue;
        if(hasCycle(nx, ny)) return true;
    }
    vis[y][x] = 0;
    return false;
}

int solve(int x, int y) {
    if(x<0||x>=M||y<0||y>=N) return 0;
    if(arr[y][x] == 'H') return 0;
    int &ret = dp[y][x];
    if(ret != -1) return ret;
    ret = 0;
    for(int i=0; i<4; i++) {
        int nx = x + dx[i] * (arr[y][x] - '0');
        int ny = y + dy[i] * (arr[y][x] - '0');
        int res = solve(nx, ny);
        ret = max(ret, res + 1);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    arr.resize(N, vector<char>(M));
    vis.assign(N, vector<int>(M, 0));
    finished.assign(N, vector<int>(M, 0));
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<N; i++) {
        string s;
        cin >> s;
        for(int j=0; j<M; j++) {
            arr[i][j] = s[j];
        }
    }
    if(hasCycle(0, 0)) cout << -1;
    else cout << solve(0, 0);
}