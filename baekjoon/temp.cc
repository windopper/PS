#include <bits/stdc++.h>

using namespace std;
string s1, s2;
int dp[4001][4001];

int dfs(int l, int r, int v) {
    if(s1.size() == l || s2.size() == r) return v + 1;
    int &ret = dp[l][r];
    if(ret != 0) return ret;
    for(int i=r; i<s2.size(); i++) {
        if(s1[l] == s2[i]) ret = max(ret, dfs(l+1, i+1, v+1)); 
    }    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s1 >> s2;
    for(int i=1; i<=s1.size(); i++) {
        for(int j=1; j<=s2.size(); j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    
}