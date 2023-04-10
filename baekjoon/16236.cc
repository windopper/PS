#include <bits/stdc++.h>

using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
vector<vector<int>> arr;
pair<int, int> babyShark;
int eat = 0;
int size = 2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    arr.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 9) {
                babyShark = {j, i};
                arr[i][j] = 0;
            }
        }
    }

    int time = 0;
    while (1) {
        int remainCanEat = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j] <= size && arr[i][j] != 0) ++remainCanEat;
            }
        }

        if (remainCanEat == 0) break;

        bool ate = false;
        queue<vector<int>> q;
        vector<vector<int>> vis(N, vector<int>(N, 0));
        q.push({babyShark.first, babyShark.second, 0});
        vis[babyShark.second][babyShark.first] = 1;
        while (!q.empty()) {
            vector<int> cur = q.front();
            q.pop();
            int curX = cur[0];
            int curY = cur[1];
            int curTime = cur[2];
            if (arr[curY][curX] > 0 && arr[curY][curX] < size) {
                time += curTime;
                arr[curY][curX] = 0;
                ++eat;
                if (eat == size) {
                    eat = 0;
                    ++size;
                }
                babyShark.first = curX;
                babyShark.second = curY;
                ate = true;
                break;
            }

            for (int i = 0; i < 4; i++) {
                int nx = curX + dx[i];
                int ny = curY + dy[i];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (vis[ny][nx]) continue;
                if (arr[ny][nx] > size) continue;
                vis[ny][nx] = 1;
                q.push({nx, ny, curTime + 1});
            }
        }

        if (!ate) break;
    }

    cout << time;
}