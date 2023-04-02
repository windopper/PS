#include <bits/stdc++.h>

using namespace std;
int N;
long long arr[1500001][2];
long long dp[1500001];

long long solve(int day) {
    if(day == N+1) return 0;
    long long& ret = dp[day];
    if(ret != -1) return ret;
    ret = 0;
    if (day + arr[day][0] <= N + 1) {
        ret = max(ret, solve(day + arr[day][0]) + arr[day][1]);
    }
    ret = max(ret, solve(day + 1));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=1; i<N+1; i++) {
        int t, p;
        cin >> t >> p;
        arr[i][0] = t;
        arr[i][1] = p;
    }
    memset(dp, -1, sizeof(dp));

    cout << solve(1);
}