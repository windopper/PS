#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
vector<string> vec;
const int INF = 987654321;
pii start = {-1, -1};
pii endd = {-1, -1};
vector<int> startDir;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

vector<int> dir[4] = {{0, 2, 3}, {1, 2, 3}, {2, 0, 1}, {3, 0, 1}};

struct comp {
    bool operator()(vector<int>& a, vector<int>& b) { return a[0] > b[0]; };
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vec.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
        for (int j = 0; j < N; j++) {
            if (vec[i][j] == '#') {
                if (start == make_pair(-1, -1)) {
                    start = {j, i};
                } else {
                    endd = {j, i};
                }
            }
        }
    }

    priority_queue<vector<int>, vector<vector<int>>, comp> pq;
    vector<vector<vector<int>>> dist(N, vector<vector<int>>(N, vector<int>(4, INF)));
    for (int i = 0; i < 4; i++) {
        pq.push({start.first, start.second, i});
        dist[start.second][start.first][i] = 0;
    }
    while (!pq.empty()) {
        vector<int> cur = pq.top();
        pq.pop();
        int x = cur[0];
        int y = cur[1];
        int d = cur[2];
        int c = dist[y][x][d];
        // cout << x << " " << y << " " << c << '\n';
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if (vec[ny][nx] == '*')
            continue;
        else if (vec[ny][nx] == '#' && dist[ny][nx][d] > c) {
            dist[ny][nx][d] = c;
        } else if (vec[ny][nx] == '.' && dist[ny][nx][d] > c) {
            dist[ny][nx][d] = c;
            pq.push({nx, ny, d});
        } else if (vec[ny][nx] == '!') {
            if (dist[ny][nx][d] > c) {
                dist[ny][nx][d] = c;
                pq.push({nx, ny, d});
            }
            if (dist[ny][nx][dir[d][1]] > c + 1) {
                // cout << nx << " " << ny << " " << c << '\n';
                dist[ny][nx][dir[d][1]] = c + 1;
                pq.push({nx, ny, dir[d][1]});
            }
            if (dist[ny][nx][dir[d][2]] > c + 1) {
                // cout << nx << " " << ny << " " << c << '\n';
                dist[ny][nx][dir[d][2]] = c + 1;
                pq.push({nx, ny, dir[d][2]});
            }
        }
    }

    int res = INF;
    // cout << endd.first << " " << endd.second << '\n';
    for (int i = 0; i < 4; i++) {
        res = min(res, dist[endd.second][endd.first][i]);
    }
    cout << res;
}