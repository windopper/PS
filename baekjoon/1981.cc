#include <bits/stdc++.h>

using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int arr[101][101];
int n;

bool pass(int x, int y, int m) {
    vector<vector<int>> visited(n, vector<int>(n, 0));
    queue<vector<int>> q;
    q.push({x, y, arr[y][x], arr[y][x]});
    while(!q.empty()) {
        vector<int> cur = q.front();
        q.pop();
        if(cur[0] == n-1 && cur[1] == n-1) return true;
        if(visited[cur[0]][cur[1]]) continue;
        visited[cur[0]][cur[1]] = 1;

        for(int i=0; i<4; i++) {
            int nx = cur[0] + dx[i];
            int ny = cur[1] + dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
            int t1 = max(cur[2], arr[ny][nx]);
            int t2 = min(cur[3], arr[ny][nx]);
            if(t1 - t2 > m) continue;
            q.push({nx, ny, t1, t2});
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    int s = 0;
    int e = 200;
    int ans = 0;
    while(s<=e) {
        int m = (s+e)/2;
        bool status = pass(0, 0, m);
        // 통과하면 더 줄여도 되겠다
        if(status) {
            e = m-1;
            ans = m-1;
        }
        else {
            s = m+1;
            ans = m+1;
        }
    }
    if(ans < 0) ans = 0;
    cout << ans;

}