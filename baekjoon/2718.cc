#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> dp;

int solve(int cur, int st) {
    if (cur == N) return 1;
    int &ret = dp[cur][st];
    if(ret != -1) return ret;
    ret = 0;
    if (st == 0) {
        if (cur + 1 < N) {
            ret += solve(cur + 2, 0);
            ret += solve(cur + 1, 9);
            ret += solve(cur + 1, 12);
            ret += solve(cur + 1, 3);
        }
        ret += solve(cur + 1, 0);
    } else if (st == 3) {
        if (cur + 1 < N) {
            ret += solve(cur + 1, 12);
        }
        ret += solve(cur + 1, 0);
    } else if (st == 6) {
        if (cur + 1 < N) {
            ret += solve(cur + 1, 9);
        }
    } else if (st == 9) {
        if (cur + 1 < N) {
            ret += solve(cur + 1, 6);
        }
        ret += solve(cur + 1, 0);
    } else if (st == 12) {
        if (cur + 1 < N) {
            ret += solve(cur + 1, 3);
        }
        ret += solve(cur + 1, 0);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        dp.assign(N, vector<int>(16, -1));
        cout << solve(0, 0) << '\n';
    }
}