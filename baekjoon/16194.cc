#include <bits/stdc++.h>
#include <ios>

using namespace std;
const int MAX = 100000000;
int N;
int arr[10001];
int dp[10001];

int solve(int cur) {
    if(cur == N) {
        return 0;
    }
    int &ret = dp[cur];
    if(ret != MAX) return ret;
    for(int i=1; i<N+1; i++) {
        if(cur + i > N) continue;
        int c = solve(cur + i) + arr[i];
        ret = min(ret, c);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=1; i<N+1; i++) {
        cin >> arr[i];
    }

    for(int i=1; i<N+1; i++) dp[i] = MAX;

    int ans = MAX;

    for(int i=1; i<N+1; i++) {
        ans = min(ans, solve(i) + arr[i]);
    }

    cout << ans;
}