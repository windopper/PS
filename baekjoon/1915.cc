#include <bits/stdc++.h>

using namespace std;
int n, m;
int arr[1001][1001];
int dp[1001][1001];
int dx[4] = {0, 1, 1, 0};
int dy[4] = {1, 1, 0, 0};
int ans = 0;

// 해당 좌표에서 구할 수 있는 가장 큰 정사각형의 너비
int dfs(int x, int y, int d) {
    
    int &ret = dp[y][x];
    if(ret != -1) return ret;
    bool chk = true;
    ret = d;

    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<1 || nx>=m+1 || ny<1 || ny>=n+1) {
            chk = false;
            break;
        }
        if(arr[ny][nx] == 0) {
            chk = false;
            break;
        }
    }

    if(!chk) {
        return ret;
    }
    ret = max(ret, dfs(x+1, y+1, d+1));

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    for(int i=1; i<n+1; i++) {
        string s;
        cin >> s;
        for(int j=0; j<m; j++) {
            arr[i][j+1] = s[j] - '0';
        }
    }

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++) {
            ans = max(ans, dfs(j, i, 1));
        }
    }

    cout << pow(ans, 2);
}