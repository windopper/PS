#include <bits/stdc++.h>

using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int N, M, K;
vector<string> arr;

int solve() {
    queue<vector<int>> q;
    q.push({0, 0, 0, 0});
    vector<vector<vector<bool>>> dis(K+1, vector<vector<bool>>(N, vector<bool>(M, false)));
    dis[0][0][0] = true;
    while(!q.empty()) {
        vector<int> cur = q.front();
        int x = cur[0];
        int y = cur[1];
        int cost = cur[2];
        int used = cur[3];
        q.pop();
        if(x == M-1 && y == N-1) {
            return cost+1;
        }

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0||nx>=M||ny<0||ny>=N) continue;
            if(arr[ny][nx] == '1') {
                if(used + 1 <= K && !dis[used+1][ny][nx]) {
                    dis[used+1][ny][nx] = true;
                    q.push({nx, ny, cost+1, used+1});
                }
            }
            else {
                if(!dis[used][ny][nx]) {
                    dis[used][ny][nx] = true;
                    q.push({nx, ny, cost+1, used});
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
    arr.resize(N);
    for(int i=0; i<N; i++) {
        string s;
        cin >> s;
        arr[i] = s;
    }   
    cout << solve();
}