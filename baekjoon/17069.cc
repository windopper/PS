#include <bits/stdc++.h>

using namespace std;
int N;
int arr[33][33];
vector<vector<vector<long long>>> dp;

// 가로 세로 대각선
// 0 1 2
long long dfs(int x, int y, int status) {
    if (x >= N || y >= N) return 0;
    if (x == N - 1 && y == N - 1) return 1;
    if (dp[y][x][status] != -1) return dp[y][x][status];

    long long ret = 0;
    if (status == 0) {
        if (!arr[y][x + 1]) {
            ret += dfs(x + 1, y, 0);
        }
        if (!arr[y][x + 1] && !arr[y + 1][x + 1] && !arr[y + 1][x]) {
            ret += dfs(x + 1, y + 1, 2);
        }
        return dp[y][x][0] = ret;
    } else if (status == 1) {
        if (!arr[y + 1][x]) {
            ret += dfs(x, y + 1, 1);
        }
        if (!arr[y][x + 1] && !arr[y + 1][x + 1] && !arr[y + 1][x]) {
            ret += dfs(x + 1, y + 1, 2);
        }
        return dp[y][x][1] = ret;
    } else {
        if (!arr[y][x + 1]) {
            ret += dfs(x + 1, y, 0);
        }
        if (!arr[y + 1][x]) {
            ret += dfs(x, y + 1, 1);
        }
        if (!arr[y][x + 1] && !arr[y + 1][x + 1] && !arr[y + 1][x]) {
            ret += dfs(x + 1, y + 1, 2);
        }
        return dp[y][x][2] = ret;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    dp.resize(N, vector<vector<long long>>(N, vector<long long>(3, -1)));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    cout << dfs(1, 0, 0);
}