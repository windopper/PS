#include <bits/stdc++.h>

using namespace std;
int h, w;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
vector<vector<vector<int>>> dp;
vector<string> arr;
const int INF = numeric_limits<int>::max();

struct comp {
    bool operator()(vector<int>& a, vector<int>& b) { return a[0] > b[0]; }
};

int solve(vector<pair<int, int>>& prisoners) {
    priority_queue<vector<int>, vector<vector<int>>, comp> pq;
    pair<int, int> p = prisoners[0];
    dp[p.second][p.first][0] = 0;
    pq.push({0, p.first, p.second});

    int ret = INF;

    while (!pq.empty()) {
        int cost = pq.top()[0];
        int x = pq.top()[1];
        int y = pq.top()[2];
        pq.pop();

        // cout << cost << " " << cur << '\n';

        if (dp[y][x][0] < cost) continue;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
                continue;
            }
            if (arr[ny][nx] == '*') continue;

            int nextCost = cost;
            if (arr[ny][nx] == '#') nextCost++;
            if (dp[ny][nx][0] > nextCost) {
                dp[ny][nx][0] = nextCost;
                pq.push({nextCost, nx, ny});
            }
        }
    }

    p = prisoners[1];
    dp[p.second][p.first][1] = 0;
    pq.push({0, p.first, p.second});

    while (!pq.empty()) {
        int cost = pq.top()[0];
        int x = pq.top()[1];
        int y = pq.top()[2];
        pq.pop();

        //cout << cost << " " << '\n';

        if (dp[y][x][1] < cost) continue;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
                ret = min(ret, cost + dp[y][x][0]);
                continue;
            }
            if (arr[ny][nx] == '*') continue;

            int nextCost = cost;
            if (arr[ny][nx] == '#' && dp[ny][nx][0] == INF) nextCost++;
            if (dp[ny][nx][1] > nextCost) {
                dp[ny][nx][1] = nextCost;
                pq.push({nextCost, nx, ny});
            }
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for (; T > 0; --T) {
        cin >> h >> w;
        dp.assign(101, vector<vector<int>>(101, vector<int>(2, INF)));
        arr.clear();
        vector<pair<int, int>> prisoners;
        for (int i = 0; i < h; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < w; j++) {
                if (s[j] == '$') {
                    prisoners.push_back({j, i});
                }
            }
            arr.push_back(s);
        }

        cout << solve(prisoners) << '\n';
        for (int k = 0; k < 2; k++) {
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if(dp[i][j][k] == INF) cout << '-';
                    else cout << dp[i][j][k];
                }
                cout << endl;
            }
            cout << "\n\n";
        }
    }
}