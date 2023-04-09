#include <bits/stdc++.h>

using namespace std;
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
vector<vector<vector<vector<int>>>> fireballs;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M, K;
    cin >> N >> M >> K;
    fireballs.resize(N, vector<vector<vector<int>>>(N));
    for (int i = 0; i < M; i++) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        --r;
        --c;
        fireballs[r][c].push_back({m, s, d});
    }

    for (; K > 0; --K) {
        vector<vector<vector<vector<int>>>> moved(N, vector<vector<vector<int>>>(N));
        vector<vector<vector<vector<int>>>> newFireballs(N, vector<vector<vector<int>>>(N));
        // move
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (fireballs[i][j].empty()) continue;
                for (vector<int> fireball : fireballs[i][j]) {
                    int mass = fireball[0];
                    int speed = fireball[1];
                    int dir = fireball[2];
                    int nx = j + dx[dir] * speed;
                    int ny = i + dy[dir] * speed;
                    nx = (nx + 1000) % N;
                    ny = (ny + 1000) % N;
                    moved[ny][nx].push_back({mass, speed, dir});
                }
            }
        }
        // merge
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (moved[i][j].empty()) continue;
                if (moved[i][j].size() >= 2) {
                    int newMass = 0;
                    int newSpeed = 0;
                    vector<int> newDir;
                    bool isAllOdd = true;
                    bool isAllEven = true;
                    for (vector<int> fireball : moved[i][j]) {
                        newMass += fireball[0];
                        newSpeed += fireball[1];
                        if (fireball[2] % 2 == 1) {
                            isAllEven = false;
                        } else
                            isAllOdd = false;
                    }
                    newMass /= 5;
                    // vanish
                    if (newMass == 0) continue;

                    newSpeed /= moved[i][j].size();
                    if ((isAllOdd && !isAllEven) || (!isAllOdd && isAllEven)) {
                        newDir = {0, 2, 4, 6};
                    } else
                        newDir = {1, 3, 5, 7};
                    // divide
                    for (int k = 0; k < 4; k++) {
                        newFireballs[i][j].push_back({newMass, newSpeed, newDir[k]});
                    }
                }
                else {
                    newFireballs[i][j].push_back(moved[i][j][0]);
                }
            }
        }

        fireballs = newFireballs;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (vector<int> fireball : fireballs[i][j]) {
                ans += fireball[0];
            }
        }
    }

    cout << ans;
}