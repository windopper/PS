#include <bits/stdc++.h>

using namespace std;
long long dp[68];

long long solve(int cur) {
    if(cur < 2) return 1;
    else if(cur == 2) return 2;
    else if(cur == 3) return 4;
    long long &ret = dp[cur];
    if(ret != 0) return ret;
    return ret = solve(cur-1) + solve(cur-2) + solve(cur-3) + solve(cur-4);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for(; t>0; --t) {
        int n;
        cin >> n;
        cout << solve(n) << "\n";
    }
}