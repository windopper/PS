#include <bits/stdc++.h>

using namespace std;
int M, N, K;
vector<vector<int>> arr;
vector<vector<int>> vis;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
        if (vis[ny][nx] || arr[ny][nx] == 0) continue;
        vis[ny][nx] = 1;
        dfs(nx, ny);
    }
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if (vis[ny][nx] || arr[ny][nx] == 0) continue;
            vis[ny][nx] = 1;
            q.push({nx, ny});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> M >> N >> K;
        int ans = 0;
        arr.assign(N, vector<int>(M, 0));
        vis.assign(N, vector<int>(M, 0));
        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            arr[y][x] = 1;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (vis[i][j] || arr[i][j] == 0) continue;
                vis[i][j] = 1;
                ++ans;
                // bfs(j, i);
                // dfs(j, i)
            }
        }
        cout << ans << '\n';
    }
}