#include <bits/stdc++.h>

using namespace std;
int dp[101];

int solve(int remain, int select, bool buffer) {
    if (remain == 0) return 1;
    int &ret = dp[remain];
    if (ret != -1) return ret;
    ret = 0;
    if (select) {
        ret = max(ret, solve(remain - 1, select, true));
    } else {
        
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
}