#include <bits/stdc++.h>

using namespace std;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int N, M, K;
int dp[101][101][80];
string target;
vector<string> arr;

int solve(int x, int y, int cur) {
    if(cur == target.size()) return 1;
    int &ret = dp[y][x][cur];
    if(ret != -1) return ret;
    ret = 0;
    for(int i=0; i<4; i++) {
        for(int j=1; j<=K; j++) {
            int nx = x + dx[i] * j;
            int ny = y + dy[i] * j;
            if(nx<0||nx>=M||ny<0||ny>=N) continue;
            if(target[cur] == arr[ny][nx]) {
                ret += solve(nx, ny, cur + 1);
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> N >> M >> K;
    arr.resize(N);
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    cin >> target;
    int ans = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(target[0] != arr[i][j]) continue;
            ans += solve(j, i, 1);
        }
    }
    cout << ans;
}