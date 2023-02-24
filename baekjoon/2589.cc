#include <bits/stdc++.h>
#include <limits>
#include <random>

using namespace std;
int N, M;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
vector<vector<char>> arr;
vector<pair<int, int>> treasures;

int bfs(int x, int y) {
    int res = 0;
    int dist[N][M];
    bool visited[N][M];
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {dist[i][j] = 0; visited[i][j] = false;}
    }
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[y][x] = true;
    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + cx;
            int ny = dy[i] + cy;
            if (nx < 0 || nx >= M || ny < 0 || ny >= N)
                continue;
            if (arr[ny][nx] == 'L' && !visited[ny][nx]) {
                visited[ny][nx] = true;
                dist[ny][nx] = dist[cy][cx] + 1;
                res = max(res, dist[ny][nx]);
                q.push({nx, ny});
          }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        vector<char> vec;
        for(int j=0; j<M; j++) {
            char tmp;
            cin >> tmp;
            if(tmp == 'L') treasures.push_back({j, i});
            vec.push_back(tmp);
        }
        arr.push_back(vec);
    }

    int res = 0;
    for(int i=0; i<treasures.size(); i++) {
        int x = treasures[i].first;
        int y = treasures[i].second;
        res = max(bfs(x, y), res);
    }
    cout << res;
}