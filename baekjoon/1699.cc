#include <bits/stdc++.h>
#include <limits>

using namespace std;
int N;
int sq;
int dp[100001];

int solve(int cur) {
    if(cur == 0) return 0;
    int &ret = dp[cur];
    if(ret != 0) return ret;
    ret = numeric_limits<int>::max();
    for(int i=1; i<=sq; i++) {
        if(cur - pow(i, 2) < 0) continue;
        ret = min(ret, solve(cur - pow(i, 2)) + 1);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    sq = floor(sqrt(N));
    cout << solve(N);
}