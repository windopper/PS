#include <bits/stdc++.h>

using namespace std;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<vector<int>> arr;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    arr.resize(N, vector<int>(M));
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    while(1) {
        vector<vector<int>> exposed(N, vector<int>(M, 0));

        int cheeseRemain = 0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(arr[i][j] == 1) ++cheeseRemain;
            }
        }

        if(cheeseRemain == 0) {
            break;
        }

        queue<pair<int, int>> q;
        vector<vector<int>> vis(N, vector<int>(M, 0));
        vector<pair<int, int>> outAir;
        q.push({0, 0});
        while(!q.empty()) {
            pair<int ,int> cur = q.front();
            q.pop();
            for(int i=0; i<4; i++) {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if(nx<0 || nx>=M || ny<0 || ny>=N) continue;
                if(arr[ny][nx] == 1) continue;
                if(vis[ny][nx]) continue;
                vis[ny][nx] = 1;
                outAir.push_back({nx, ny});
                q.push({nx, ny});
            }
        }

        for(pair<int, int> p : outAir) {
            int x = p.first;
            int y = p.second;
            for(int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx <0 || nx>=M || ny<0 || ny>=N) continue;
                if(arr[ny][nx] == 1) ++exposed[ny][nx];
            }
        }
    

        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(exposed[i][j] >= 2) arr[i][j] = 0;
            }
        }

        ++ans;
    }

    cout << ans;
}