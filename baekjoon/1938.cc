#include <bits/stdc++.h>

using namespace std;
vector<string> arr;
vector<pair<int ,int>> start;
pair<int ,int> startLoc;
int startRotate = 0; // 0 -> horizontal  1 -> vertical
vector<pair<int ,int>> goal;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int N;

bool isOutOfRange(int x, int y) {
    return x<0||x>=N||y<0||y>=N;
}

bool isArrived(int x, int y, int rotate) {
    if(rotate == 1) {
        --y;
    }
    else {
        --x;
    }
    for(int i=0; i<3; i++) {
        if(x != goal[i].first || y != goal[i].second) {
            return false;
        }
        if(rotate == 1) {
            ++y;
        }
        else ++x;
    }
    return true;
}
/**
 * @return true when rotated successfully
*/
bool rotate(int x, int y, int rotate) {
    bool isHorizontal = false;
    int originX = x;
    int originY = y;
    if(rotate == 1) {
        --y;
    }
    else --x;
    if(x < originX) isHorizontal = true;
    int curX = x;
    int curY = y;

    for(int i=-1; i<2; i++) {
        for(int j=0; j<3; j++) {
            if(isHorizontal) {
                int nx = curX + j;
                int ny = curY + i;
                if(isOutOfRange(nx, ny)) return false;
                if(arr[ny][nx] == '1') return false;
            }   
            else {
                int nx = curX + i;
                int ny = curY + j;
                if(isOutOfRange(nx, ny)) return false;
                if(arr[ny][nx] == '1') return false;
            }
        }
    }

    return true;
}

/**
 * @return true when moved successfully
*/
bool move(int dir, int x, int y, int rotate) {
    if(rotate == 1) {
        --y;
    }
    else {
        --x;
    }
    for(int i=0; i<3; i++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(isOutOfRange(nx, ny)) return false;
        if(arr[ny][nx] == '1') return false;
        if(rotate == 1) {
            ++y;
        }
        else ++x;
    }
    return true;
}

int bfs() {
    queue<vector<int>> q;
    vector<vector<vector<int>>> vis(N, vector<vector<int>>(N, vector<int>(2, 0)));
    q.push({startLoc.first, startLoc.second, startRotate, 0});
    vis[startLoc.second][startLoc.first][startRotate] = 1;
    while(!q.empty()) {
        vector<int> cur = q.front();
        q.pop();
        if(isArrived(cur[0], cur[1], cur[2])) {
            return cur[3];
        }

        for(int i=0; i<5; i++) {
            if(i <= 3) {
                if(move(i, cur[0], cur[1], cur[2])) {
                    int nx = cur[0] + dx[i];
                    int ny = cur[1] + dy[i];
                    if(isOutOfRange(nx, ny)) continue;
                    if(vis[ny][nx][cur[2]]) continue;
                    vis[ny][nx][cur[2]] = 1;
                    q.push({nx, ny, cur[2], cur[3] + 1});
                }
            }
            else {
                if(rotate(cur[0], cur[1], cur[2])) {
                    if(vis[cur[1]][cur[0]][1-cur[2]]) continue;
                    vis[cur[1]][cur[0]][1-cur[2]] = 1;
                    q.push({cur[0], cur[1], 1-cur[2], cur[3]+1});
                }
            }   
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    int cnt = 0;
    pair<int ,int> first;
    for(int i=0; i<N; i++) {
        string s;
        cin >> s;
        arr.push_back(s);
        for(int j=0; j<N; j++) {
            if(s[j] == 'B') {
                ++cnt;
                if(cnt == 1) {
                    first = {j, i};
                }
                else if(cnt == 2) {
                    if(first.first + 1 == j) startRotate = 0;
                    else if(first.second + 1 == i) startRotate = 1;
                    startLoc = {j, i};
                }

                arr[i][j] = '0';
            }
            else if(s[j] == 'E') {
                goal.push_back({j, i});
                arr[i][j] = '0';
            }
        }
    }

    cout << bfs();
}