#include <bits/stdc++.h>

using namespace std;
int h, w;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int dp[101][101];
vector<string> arr;
const int MAX = numeric_limits<int>::max();

int solve(int x, int y) {
    if(x<0||x>=w||y<0||y>=h) {
        return 0;        
    }
    int &ret = dp[y][x];
    if(ret != -1) return ret;
    ret = 987654321;
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0||nx>=w||ny<0||ny>=h) {
            ret = min(ret, solve(nx, ny));
        }
        else {
            if(arr[ny][nx] == '*') continue;
            else if(arr[ny][nx] == '.') ret = min(ret, solve(nx, ny));
            else if(arr[ny][nx] == '#') ret = min(ret, solve(nx, ny) + 1);
        }
    }
    cout << x << " " << y << " " << ret << "\n";
    return ret;
}

int solve(vector<pair<int ,int>>& prisoners) {
    vector<vector<vector<int>>> dis(h, vector<vector<int>>(w, vector<int>(2)));
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            for(int k=0; k<2; k++) dis[i][j][k] = MAX;
        }
    }
    priority_queue<vector<int>> q;
    q.push({0, prisoners[0].first, prisoners[0].second});
    int ans = 0;
    while(!q.empty()) {
        vector<int> cur = q.top();
        q.pop();
        int x = cur[1];
        int y = cur[2];
        int cnt = -cur[0];
        cout << x << " " << y << " " << cnt << '\n';
        if(dis[y][x][0] != MAX) {
            continue;
        }

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0||nx>=w||ny<0||ny>=h) {
                ans += cnt;
                continue;
            }
            if(arr[ny][nx] == '*') continue;
            if(arr[ny][nx] == '#' && dis[ny][nx][0] > cnt + 1) {
                dis[ny][nx][0] = cnt + 1;
                q.push({-cnt - 1, nx, ny});
                continue;
            }
            dis[ny][nx][0] = cnt;
            q.push({-cnt, nx, ny});
        }
    }

    q.push({0, prisoners[1].first, prisoners[1].second});

    while(!q.empty()) {
        vector<int> cur = q.top();
        q.pop();
        int x = cur[1];
        int y = cur[2];
        int cnt = -cur[0];
        //cout << x << " " << y << " " << cnt << '\n';
        if(dis[y][x][1] <= cnt) {
            continue;
        }

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(dis[ny][nx][0] > 0) {
                ans += cnt;
                continue;
            }
            if(arr[ny][nx] == '*') continue;
            if(arr[ny][nx] == '#' && dis[ny][nx][1] > cnt + 1) {
                dis[ny][nx][1] = cnt + 1;
                q.push({-cnt - 1, nx, ny});
                continue;
            }
            dis[ny][nx][1] = cnt;
            q.push({-cnt, nx, ny});
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for(; T>0; --T) {
        cin >> h >> w;
        memset(dp, -1, sizeof(dp));
        arr.clear();
        vector<pair<int, int>> prisoners;
        for(int i=0; i<h; i++) {
            string s;
            cin >> s;
            for(int j=0; j<w; j++) {
                if(s[j] == '$') {
                    s[j] = '.';
                    prisoners.push_back({j, i});
                }
            }
            arr.push_back(s);
        }

        int ans = 0;
        cout << solve(prisoners);
    }

}