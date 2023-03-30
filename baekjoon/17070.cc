#include <bits/stdc++.h>

using namespace std;
int N;
int dp[17][17][3];
int arr[17][17];

bool isOut(int x, int y) {
    return x < 0 || x>=N || y<0 || y>=N;
}

int solve(int x, int y, int type) {
    if(x == N-1 && y == N-1) return 1;
    int &ret = dp[y][x][type];
    if(ret != -1) return ret;
    ret = 0;
    if(type != 2 && !isOut(x+1, y) && arr[y][x+1] == 0) ret += solve(x+1, y, 0);
    if(type != 0 && !isOut(x, y+1) && arr[y+1][x] == 0) {
        ret += solve(x, y+1, 2);
    }
    if(!isOut(x+1, y+1) && arr[y+1][x] == 0 && arr[y][x+1] == 0 && arr[y+1][x+1] == 0) {
        ret += solve(x+1, y+1, 1);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) cin >> arr[i][j];
    }
    cout << solve(1, 0, 0);
}