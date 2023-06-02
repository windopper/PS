#include <bits/stdc++.h>

using namespace std;
int N, M;
int dp[31][31];

long long combination(int cnt, int cur) {
    if(cnt == N) {
        return 1;
    }
    int &ret = dp[cur][cnt];
    if(ret != -1) return ret;
    ret = 0;
    for(int i=cur; i<M; ++i) {
        ret += combination(cnt + 1, i + 1);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        cin >> N >> M;
        for(int i=0; i<31; i++) for(int j=0; j<31; j++) dp[i][j] = -1;
        cout << combination(0, 0) << '\n';
    }   
}