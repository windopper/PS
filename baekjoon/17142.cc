#include <bits/stdc++.h>

using namespace std;
int N, M;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ans = 987654321;
const int INF = 987654321;
vector<pair<int, int>> virus;
vector<vector<int>> arr;

void solve(int cur, vector<int>& selected) {
    if (selected.size() == M) {
        int time = 0;
        queue<vector<int>> q;
        vector<vector<int>> vis(N, vector<int>(N, INF));
        for (int s : selected) {
            q.push({virus[s].first, virus[s].second, 0, 0});
            vis[virus[s].second][virus[s].first] = 0;
            arr[virus[s].second][virus[s].first] = 0;
        }
        while (!q.empty()) {
            vector<int> cur = q.front();
            q.pop();
            int x = cur[0];
            int y = cur[1];
            int t = cur[2];
            int ct = cur[3];
            if (vis[y][x] < t) continue;
            //if(t > ans) return;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (arr[ny][nx] == 1) continue;
                if (arr[ny][nx] == 0 && vis[ny][nx] > t + 1) {
                    int alt = t;
                    int newCt = ct;
                    if(arr[y][x] == 2) {
                        alt += ct;
                        newCt = 0;
                    }
                    vis[ny][nx] = alt + 1;
                    q.push({nx, ny, alt + 1, newCt});
                } else if (arr[ny][nx] == 2 && vis[ny][nx] > t) {
                    int alt = t;
                    vis[ny][nx] = alt;
                    q.push({nx, ny, alt, ct+1});
                }
            }
        }
        for (int s : selected) {
            arr[virus[s].second][virus[s].first] = 2;
        }
        int ret = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j] != 1) {
                    ret = max(ret, vis[i][j]);
                }
                if (arr[i][j] != 1 && vis[i][j] == INF) {
                    return;
                }
            }
        }
        
        ans = min(ret, ans);
        return;
    }

    for (int i = cur; i < virus.size(); i++) {
        selected.push_back(i);
        solve(i + 1, selected);
        selected.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    arr.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                virus.push_back({j, i});
            }
        }
    }
    vector<int> selected;
    solve(0, selected);
    if(ans == INF) cout << -1;
    else cout << ans;
}