#include <bits/stdc++.h>

using namespace std;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int N, M;
int arr[101][101];

int solve() {
    queue<vector<int>> q;
    q.push({0, 0, 0});
    vector<vector<int>> visited(N, vector<int>(M, -1));
    visited[0][0] = 0;
    while(!q.empty()) {
        vector<int> cur = q.front();
        q.pop();
        if(cur[0] == M-1 && cur[1] == N-1) {
            return cur[2]+1;
        }
        for(int i=0; i<4; i++) {
            int nx = cur[0] + dx[i];
            int ny = cur[1] + dy[i];
            if(nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if(arr[ny][nx] == '0') continue;
            if(visited[ny][nx] >= cur[2] + 1) continue;
            visited[ny][nx] = cur[2] + 1;
            q.push({nx, ny, cur[2] + 1});
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        string s;
        cin >> s;
        for(int j=0; j<M; j++) {
            arr[i][j] = s[j];
        }
    }

    cout << solve();
}