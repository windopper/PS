#include <bits/stdc++.h>

using namespace std;
int N;
int arr[100][100];
long long dp[100][100];

long long solve(short x, short y) {
    if(x<0 || x>=N || y<0 || y>=N) return 0;
    if(arr[y][x] == 0 && x == N-1 && y == N-1) return 1;
    if(arr[y][x] == 0) return 0;
    long long &ret = dp[y][x];
    if(ret != -1) return ret;
    ret = solve(x+arr[y][x], y) + solve(x, y+arr[y][x]);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }
    cout << solve(0, 0);
}