#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
vector<string> vec;
const int INF = 987654321;
pii start = {0, 0};
vector<int> startDir;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

vector<int> dir[4] = {{0, 2, 3}, {1, 2, 3}, {2, 0, 1}, {3, 0, 1}};
int cd[4] = {0, 0, 1, 1};

struct comp {
    bool operator() (vector<int>& a, vector<int>& b) {
        return a[0] > b[0];
    };
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
        if (start != make_pair(0, 0)) continue;
        for (int j = 0; j < N; j++) {
            if (vec[i][j] == '#') {
                start = {j, i};
                for (int k = 0; k < 4; k++) {
                    int nx = j + dx[k];
                    int ny = i + dy[k];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (vec[ny][nx] != '*') startDir.push_back(k);
                }
            }
        }
    }

    priority_queue<vector<int>, vector<vector<int>>, comp> pq;
    vector<vector<vector<int>>> dist(N, vector<vector<int>>(N, vector<int>(4, INF)));
    for (int cur : startDir) {
        pq.push({0, start.first, start.second, cur});
        dist[start.second][start.first][cur] = 0;
    }
    while (!pq.empty()) {
        vector<int> cur = pq.top();
        pq.pop();
        int c = cur[0];
        int x = cur[1];
        int y = cur[2];
        int d = cur[3];
        //cout << x << " " << y << " " << c << '\n';
        if(dist[y][x][d] < c) continue;
        int nx = x + dx[d];
        int ny = y + dy[d];
        while (nx >= 0 && nx < N && ny >= 0 && ny < N) {
            //cout << nx << " " << ny << '\n';
            if(vec[ny][nx] == '*') break;
            if (vec[ny][nx] == '#') {
                cout << c;
                return 0;
            }
            if (vec[ny][nx] == '!' && dist[ny][nx][dir[d][1]] > c + 1) {
                //cout << nx << " " << ny << " " << c << '\n';
                dist[ny][nx][dir[d][1]] = c + 1;
                pq.push({c + 1, nx, ny, dir[d][1]});
            }
            if (vec[ny][nx] == '!' && dist[ny][nx][dir[d][2]] > c + 1) {
                //cout << nx << " " << ny << " " << c << '\n';
                dist[ny][nx][dir[d][2]] = c + 1;
                pq.push({c + 1, nx, ny, dir[d][2]});
            }
            nx += dx[d];
            ny += dy[d];
            // cout << nx << " " << ny << '\n';
        }
    }
}