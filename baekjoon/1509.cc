#include <bits/stdc++.h>

using namespace std;
int N;
string s;
int palin[2501][2501];
int dp[2501];

int solve(int cur) {
    if(cur >= N) return 0;
    int &ret = dp[cur];
    if(ret != -1) return ret;
    ret = 987654321;
    for(int i=cur; i<N; i++) {
        if(palin[cur][i] == 0) continue;
        ret = min(ret, solve(i+1) + 1);
    }
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    N = s.length();
    for(int i=0; i<N; i++) palin[i][i] = 1;
    for(int i=0; i<N-1; i++) if(s[i] == s[i+1]) palin[i][i+1] = 1;
    for(int i=2; i<=N-1; i++) {
        for(int l=0; l<N-i; l++) {
            int r = l + i;
            if(s[l] == s[r] && palin[l+1][r-1]) palin[l][r] = 1;
        }
    }
    cout << solve(0);
}