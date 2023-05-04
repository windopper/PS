#include <bits/stdc++.h>

using namespace std;
const int MOD = 9901;
int N, M;
int dp[15][15][1 << 17];

int solve(int x, int y, long long st) {
    cout << x << " " << y << " " << st << '\n';
    if (x == 0 && y == N) {
        if(!(st & (1 << 0)) ^ !(st & (1 << M-1))) return 1;
        return 0;
    }
    // int &ret = dp[y][x][st];
    // if (ret != -1) return ret;
    int ret = 0;

    // 바로 옆이 빈 공간일 때
    if (!(st & (1 << 0)) && x >= 1) {
        // 다음 줄로 가야되나
        if (x + 1 >= M) {
            // 바로 위에 줄이 차있으면 가능
            if (st & (1 << (M - 1)) || y == 0) {
                ret += solve(0, y + 1, (st << 1) & ~(1 << M) | 3);
            }
        } else {
            if (st & (1 << (M - 1)) || y == 0) {
                ret += solve(x + 1, y, (st << 1) & ~(1 << M) | 3);
            }
        }
    }
    // 바로 위줄이 빈 공간이라면
    if (!(st & (1 << M - 1)) && y >= 1) {
        // 다음 줄로 가야되나
        if (x + 1 >= M) {
            ret += solve(0, y + 1, (st << 1) & ~(1 << M) | 1);
        } else {
            ret += solve(x + 1, y, (st << 1) & ~(1 << M) | 1);
        }
    }

    // 바로 위줄이 있을 경우 또는 첫번째 줄일 경우
    if (st & (1 << M - 1) || (y == 0)) {
        if (x + 1 >= M) {
            ret += solve(0, y + 1, (st << 1) & ~(1 << M));
        } else {
            ret += solve(x + 1, y, (st << 1) & ~(1 << M));
        }
    }
    ret %= MOD;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> N >> M;
    cout << solve(0, 0, 0);
}