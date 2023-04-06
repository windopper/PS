#include <bits/stdc++.h>

using namespace std;
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
vector<vector<int>> arr;
int N;

void spread(int x, int y, vector<vector<int>>& status, int changeTo, int changeFrom) {
    queue<vector<int>> q;
    for (int i = 0; i < 9; i++) {
        q.push({x, y, i});
    }
    while (!q.empty()) {
        vector<int> cur = q.front();
        q.pop();
        int nx = cur[0] + dx[cur[2]];
        int ny = cur[1] + dy[cur[2]];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if (status[ny][nx] == changeFrom) {
            status[ny][nx] = changeTo;
            q.push({nx, ny, cur[2]});
        }
    }
}

int dfs(int cur, vector<vector<int>>& status) {
    if (cur == N) {
        return 1;
    }
    int ret = 0;
    for (int i = cur; i <= cur; i++) {
        for (int j = 0; j < N; j++) {
            if (status[i][j] == 0) {
                status[i][j] = 30;
                spread(j, i, status, cur + 1, 0);
                ret += dfs(cur + 1, status);
                status[i][j] = 0;
                spread(j, i, status, 0, cur + 1);
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    arr.resize(N, vector<int>(N, 0));
    cout << dfs(0, arr);
}