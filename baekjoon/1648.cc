#include <bits/stdc++.h>

using namespace std;
const int MOD = 9901;
int N, M;
int dp[15][15][1 << 14];

int solve(int x, int y, int st) {
    if(x >= 0 && y >= N && st == 0) return 1;
    if(x >= 0 && y >= N) return 0;
    int &ret = dp[y][x][st];
    if(ret != -1) return ret;
    ret = 0;
    if(st & 1) {
        if(x + 1 >= M) {
            ret += solve(0, y + 1, st >> 1);
        }
        else {
            ret += solve(x + 1, y, st >> 1);
        }
    }
    else {
        if(x + 1 >= M) {
            ret += solve(0, y + 1, (st >> 1) | (1 << (M-1)));
        }
        else {
            ret += solve(x+1, y, (st >> 1) | (1 << (M-1)));
        }
        if(x + 1 < M && (st & 2) == 0) {
            if(x + 2 >= M) ret += solve(0, y + 1, st >> 2);
            else ret += solve(x+2, y, st >> 2);
        }
    }
    return ret %= MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> N >> M;
    cout << solve(0, 0, 0);
}