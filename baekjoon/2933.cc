#include <bits/stdc++.h>

using namespace std;
vector<string> arr;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int R, C;
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;
        arr.push_back(s);
    }
    int N;
    cin >> N;
    int turn = 0;
    for (int k = 0; k < N; k++) {
        int H;
        cin >> H;
        H = R - H;

        if (turn == 0) {
            for (int i = 0; i < C; i++) {
                if (arr[H][i] == 'x') {
                    arr[H][i] = '.';
                    break;
                }
            }
        } else {
            for (int i = C - 1; i >= 0; --i) {
                if (arr[H][i] == 'x') {
                    arr[H][i] = '.';
                    break;
                }
            }
        }

        vector<vector<int>> vis(R, vector<int>(C, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < C; i++) {
            if (arr[R - 1][i] == 'x') {
                vis[R - 1][i] = 1;
                q.push({i, R - 1});
            }
        }
        // check if adjacent to ground
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
                if (vis[ny][nx]) continue;
                if (arr[ny][nx] == '.') continue;
                vis[ny][nx] = 1;
                q.push({nx, ny});
            }
        }

        // gather falling clusters
        int minFall = numeric_limits<int>::max();
        queue<pair<int, int>> cq;
        for (int i = R - 1; i >= 0; i--) {
            for (int j = 0; j < C; j++) {
                if (vis[i][j]) continue;
                if (arr[i][j] == '.') continue;
                cq.push({j, i});
                arr[i][j] = '.';
                int target = i;
                while (target < R && arr[target][j] == '.') target++;
                target -= 1;
                minFall = min(minFall, target - i);
            }
        }

        while (!cq.empty()) {
            int x = cq.front().first;
            int y = cq.front().second;
            cq.pop();
            arr[y + minFall][x] = 'x';
            arr[y][x] = '.';
        }

        turn = 1 - turn;
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << arr[i][j];
        }
        cout << "\n";
    }
}