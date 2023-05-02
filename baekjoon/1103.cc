#include <bits/stdc++.h>

using namespace std;
int N, M;
vector<vector<char>> arr;
vector<vector<int>> vis;
int dp[51][51][4];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int solve(int x, int y, int dir) {
    if(x<0||x>=M||y<0||y>=N) return 0;
    if(arr[y][x] == 'H') return 0;
    if(vis[y][x]) return -1;
    vis[y][x] = 1;
    int &ret = dp[y][x][dir];
    if(ret != -2) return ret;
    ret = 0;
    for(int i=0; i<4; i++) {
        int nx = x + dx[i] * (arr[y][x] - '0');
        int ny = y + dy[i] * (arr[y][x] - '0');
        int res = solve(nx, ny, i);
        if(res != -1 && ret != -1) ret = max(ret, res+1);
        else ret = -1;
    }
    vis[y][x] = 0;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    arr.resize(N, vector<char>(M));
    vis.assign(N, vector<int>(M, 0));
    for(int i=0; i<51; i++) for(int j=0; j<51; j++) for(int k=0; k<4; k++) dp[i][j][k] = -2;
    for(int i=0; i<N; i++) {
        string s;
        cin >> s;
        for(int j=0; j<M; j++) {
            arr[i][j] = s[j];
        }
    }

    cout << max(solve(0, 0, 1), solve(0, 0, 3));
}