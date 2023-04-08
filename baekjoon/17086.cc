#include <bits/stdc++.h>

using namespace std;
int N, M;
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 1, -1, 0, 0, -1, 1};
vector<vector<int>> arr;

int solve(int x, int y) {
    queue<vector<int>> q;
    vector<vector<int>> visited(N, vector<int>(M, 0));
    q.push({x, y, 0});
    visited[y][x] = 1;
    while(!q.empty()) {
        vector<int> cur = q.front();
        q.pop();
        if(arr[cur[1]][cur[0]] == 1) {
            return cur[2];
        }
        for(int i=0; i<8; i++) {
            int nx = cur[0] + dx[i];
            int ny = cur[1] + dy[i];
            if(nx<0 || nx>=M || ny<0 || ny>=N) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = 1;
            q.push({nx, ny, cur[2] + 1});
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    arr.resize(N, vector<int>(M));
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(arr[i][j] == 1) continue;
            ans = max(ans, solve(j, i));
        }
    }

    cout << ans;
}