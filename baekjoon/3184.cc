#include <bits/stdc++.h>

using namespace std;
int R, C;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
vector<string> arr;
vector<vector<bool>> vis(251, vector<bool>(251, false));
int sheep = 0;
int wolf = 0;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[y][x] = true;

    int localSheep = 0;
    int localWolf = 0;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        if(arr[y][x] == 'o') {
            ++localSheep;
        }
        else if(arr[y][x] == 'v') {
            ++localWolf;
        }

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0||nx>=C||ny<0||ny>=R) continue;
            if(arr[ny][nx] == '#') continue;
            if(vis[ny][nx]) continue;
            vis[ny][nx] = true;
            q.push({nx, ny});
        }
    }

    if(localWolf >= localSheep) wolf += localWolf;
    else sheep += localSheep;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> R >> C;
    for(int i=0; i<R; i++) {
        string s;
        cin >> s;
        arr.push_back(s);
    }

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(vis[i][j]) continue;
            if(arr[i][j] == '#') continue;
            bfs(j, i);
        }
    }

    cout << sheep << " " << wolf;
}