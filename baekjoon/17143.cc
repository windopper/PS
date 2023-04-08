#include <bits/stdc++.h>

using namespace std;
int dx[5] = {0, 0, 0, 1, -1};
int dy[5] = {0, -1, 1, 0, 0};
vector<vector<int>> sharks;
vector<vector<int>> arr;

int changeDir(int x) {
    if(x == 1) return 2;
    else if(x == 2) return 1;
    else if(x == 3) return 4;
    else return 3;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int R, C, M;
    cin >> R >> C >> M;
    // R -> y
    // C -> x
    sharks.push_back({});
    arr.assign(R, vector<int>(C, 0));
    for(int i=1; i<M+1; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        sharks.push_back({c-1, r-1, s, d, z});
        arr[r-1][c-1] = i;
    }

    int ans = 0;
    vector<int> fishing(M+1, 0);
    for(int i=0; i<C; i++) {
        vector<vector<int>> nextArr(R, vector<int>(C, 0));
        // fishing
        for(int j=0; j<R; j++) {
            if(arr[j][i] > 0) {
                ans += sharks[arr[j][i]][4];
                fishing[arr[j][i]] = 1;
                arr[j][i] = 0;
                break;
            }
        }

        // moving
        for(int j=1; j<M+1; j++) {
            if(fishing[j]) continue;
            vector<int>& shark = sharks[j];
            int x = shark[0];
            int y = shark[1];
            int speed = shark[2];
            int dir = shark[3];
            int size = shark[4];
            int remains = speed;

            if(dir == 1 || dir == 2) {
                remains %= (R-1) * 2;
            }
            else {
                remains %= (C-1)*2;
            }

            while(remains > 0) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(nx<0 || nx>=C || ny<0 || ny>=R) {
                    dir = changeDir(dir);
                    nx = x + dx[dir];
                    ny = y + dy[dir];
                }
                x = nx;
                y = ny;
                --remains;
            }

            shark[0] = x;
            shark[1] = y;
            shark[3] = dir;

            if(nextArr[y][x] == 0) {
                nextArr[y][x] = j;
            }
            else {
                // eating
                if(sharks[nextArr[y][x]][4] < size) {
                    fishing[nextArr[y][x]] = 1;
                    nextArr[y][x] = j;
                }
                else {
                    fishing[j] = 1;
                }
            }
        }
        arr = nextArr;

    }

    cout << ans;
}