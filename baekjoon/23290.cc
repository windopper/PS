#include <bits/stdc++.h>

using namespace std;

int dxFish[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dyFish[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dxShark[4] = {0, -1, 0, 1};
int dyShark[4] = {-1, 0, 1, 0};
int M, S, sx, sy;

vector<int> arr[5][5];
vector<int> smell[5][5];
vector<vector<int>> sharkMoves;

int rotate(int cur) {
    return cur == 0 ? 7 : cur - 1;
}

void moveShark(vector<int>& tmp, int remain, int x, int y, int eaten) {
    if(remain == 0) {
        sharkMoves.push_back({eaten, tmp[0], tmp[1], tmp[2]});
        return;
    }
    for(int i=0; i<4; i++) {
        int nx = x + dxShark[i];
        int ny = y + dyShark[i];
        if(nx<=0||nx>4||ny<=0||ny>4) continue;
        tmp.push_back(i);
        vector<int> t;
        t = arr[ny][nx];
        arr[ny][nx].clear();
        moveShark(tmp, remain - 1, nx, ny, eaten + t.size());
        arr[ny][nx] = t;
        tmp.pop_back();
    }
}

bool comp(vector<int>&a, vector<int>& b) {
    if(a[0] != b[0]) return a[0] > b[0];
    if(a[1] != b[1]) return a[1] < b[1];
    if(a[2] != b[2]) return a[2] < b[2];
    return a[3] < b[3];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> M >> S;
    for(int i=0; i<M; i++) {
        int fx, fy, d;
        cin >> fy >> fx >> d;
        arr[fy][fx].push_back(d-1);
    }

    cin >> sy >> sx;

    while(S--) {
        vector<int> copied[5][5];
        vector<int> newArr[5][5];
        for(int i=1; i<=4; i++) {
            for(int j=1; j<=4; j++) {
                for(int fish : arr[i][j]) {
                    copied[i][j].push_back(fish);
                }
            }
        }

        for(int i=1; i<=4; i++) {
            for(int j=1; j<=4; j++) {
                for(int d : arr[i][j]) {
                    bool moved = false;
                    int dir = d;
                    for(int k=0; k<8; k++) {
                        if(k != 0) dir = rotate(dir);
                        int nx = j + dxFish[dir];
                        int ny = i + dyFish[dir];
                        if(nx<=0||nx>4||ny<=0||ny>4) continue;
                        if(nx == sx && ny == sy) continue;
                        if(!smell[ny][nx].empty()) continue;
                        moved = true;
                        newArr[ny][nx].push_back(dir);
                        break;
                    }

                    if(!moved) {
                        newArr[i][j].push_back(d);
                    }
                }
            }
        }

        for(int i=1; i<=4; i++) {
            for(int j=1; j<=4; j++) {
                arr[i][j] = newArr[i][j];
            }
        }

        sharkMoves.clear();
        vector<int> tmp;
        moveShark(tmp, 3, sx, sy, 0);
        sort(sharkMoves.begin(), sharkMoves.end(), comp);
        vector<int> bestWay = sharkMoves.front();
        for(int i=1; i<=3; i++) {
            //cout << bestWay[i] << " ";
            sx += dxShark[bestWay[i]];
            sy += dyShark[bestWay[i]];
            for(int j=0; j<arr[sy][sx].size(); j++) {
                smell[sy][sx].push_back(3);
            }
            arr[sy][sx].clear();
        }

        // smell vanish and copied
        vector<int> newSmell[5][5];
        for(int i=1; i<=4; i++) {
            for(int j=1; j<=4; j++) {
                for(int s : smell[i][j]) {
                    if(s - 1 <= 0) continue;
                    newSmell[i][j].push_back(s-1);
                }
                smell[i][j] = newSmell[i][j];

                for(int d : copied[i][j]) {
                    arr[i][j].push_back(d);
                }
            }
        }
    }

    int ans = 0;
    for(int i=1; i<=4; i++) {
        for(int j=1; j<=4; j++) {
            ans += arr[i][j].size();
        }
    }
    cout << ans;
}