#include <bits/stdc++.h>

using namespace std;
int N, M;
vector<string> arr;
vector<vector<int>> dp;


int solve(int x, int y) {
    
    if(x<0 || x>=M || y<0 || y>=N) return 1;
    if(dp[y][x] != -1) return dp[y][x];

    char c = arr[y][x];
    int ret = dp[y][x] = 0;

    if(c == 'U') {
        ret = solve(x, y-1);
    }
    else if(c == 'R') {
        ret = solve(x+1, y);
    }
    else if(c == 'D') {
        ret = solve(x, y+1);
    }
    else {
        ret = solve(x-1, y);
    }

    dp[y][x] = ret;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    dp.resize(N, vector<int>(M, 0));
    for(int i=0; i<N; i++) {
        string s;
        cin >> s;
        arr.push_back(s);

        for(int j=0; j<M; j++) {
            dp[i][j] = -1;
        }
    }

    int ans = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            ans += solve(j, i);
        }
    }

    cout << ans;

}