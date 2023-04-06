#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> cctvs;
int N, M;
vector<vector<int>> arr;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
vector<vector<int>> type[5] = {
    {{0}, {1}, {2}, {3}},
    {{0, 1}, {2, 3}},
    {{1, 3}, {3, 0}, {0, 2}, {2, 1}},
    {{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}},
    {{0, 1, 2, 3}}
};

int ans = numeric_limits<int>::max();

void spread(int x, int y, vector<int>& dir, int change, vector<vector<int>>& status, int changeFrom) {
    queue<vector<int>> q;
    for(int i=0; i<dir.size(); i++) {
        q.push({x, y, dir[i]});
    }
    while(!q.empty()) {
        vector<int> cur = q.front();
        q.pop();
        int nx = cur[0] + dx[cur[2]];
        int ny = cur[1] + dy[cur[2]];
        if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
        if(status[ny][nx] == 6) continue;
        if(status[ny][nx] == changeFrom) status[ny][nx] = change;
        q.push({nx, ny, cur[2]});
    }
}

void dfs(int cur, vector<vector<int>>& status) {
    if(cur == cctvs.size()) {
        int cnt = 0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(status[i][j] == 0) ++cnt;
            }
        }
        ans = min(ans, cnt);
        return;
    }
    for (int j = 0; j < type[cctvs[cur][2]].size(); j++) {
        spread(cctvs[cur][0], cctvs[cur][1], type[cctvs[cur][2]][j], 7 + cur, status, 0);
        dfs(cur+1, status);
        spread(cctvs[cur][0], cctvs[cur][1], type[cctvs[cur][2]][j], 0, status, 7 + cur);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    arr.resize(N, vector<int>(M, 0));
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> arr[i][j];
            if(arr[i][j] > 0 && arr[i][j] < 6) {
                cctvs.push_back({j, i, arr[i][j]-1});
            }
        }
    }

    dfs(0, arr);
    cout << ans;

}