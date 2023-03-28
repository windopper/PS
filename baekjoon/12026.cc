#include <bits/stdc++.h>
#include <limits>

using namespace std;
int N;
int arr[1001];
int dp[1001];

int solve(int loc, int type) {
    if(loc == N-1) return 0;
    int &ret = dp[loc];
    if(ret != 0) return ret;
    ret = 1000001;
    for(int i=loc+1; i<N; i++) {
        if(arr[i] == (type + 1) % 3) {
            ret = min(ret, solve(i, (type + 1) % 3) + ((i - loc) * (i - loc)));
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) {
        char c; cin >> c;
        if(c == 'B') {
            arr[i] = 0;
        }
        else if(c == 'O') {
            arr[i] = 1;
        }
        else {
            arr[i] = 2;
        }
    }

    int ans = solve(0, 0);
    if(ans == 1000001) cout << -1;
    else cout << ans;
}