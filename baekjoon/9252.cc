#include <bits/stdc++.h>

using namespace std;
string M, N;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> M; cin >> N;
    int dp[N.length()+1][M.length()+1];
    for(int i=0; i<N.length()+1; i++) {
        for(int j=0; j<M.length()+1; j++) dp[i][j] = 0;
    }
    for(int i=1; i<N.length()+1; i++) {
        for(int j=1; j<M.length()+1; j++) {
            if(N[i-1] == M[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    string ans = "";
    int idx = 0;
    int row = N.length();
    int col = M.length();
    int cnt = dp[row][col];
	while (dp[row][col]) {
		if (dp[row][col] == dp[row - 1][col]) {
			row--;
		}
		else if (dp[row][col] == dp[row][col - 1]) {
			col--;
		}
		else {
			ans += M[col-1];
			row--, col--;
		}
	}
    // for(int i=1; i<M.length()+1; i++) {
    //     for(int j=idx; j<N.length()+1; j++) {
    //         if(dp[j][i] > cnt) {
    //             ans += N[j-1];
    //             ++cnt;
    //             idx = j;
    //             break;
    //         }
    //     }
    // }
    cout << cnt << "\n";
    if(cnt > 0) {
        reverse(ans.begin(), ans.end());
        cout << ans;
    }
}