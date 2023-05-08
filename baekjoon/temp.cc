#include <bits/stdc++.h>

using namespace std;
int N;
vector<int> arr;
bool VIP[51];
int dp[51][3];
vector<bool> vi(51, false);

int solve(int cur, int loc) {
    if(cur > N) return 1;
    int &ret = dp[cur][loc];
    if(ret != -1) return ret;
    ret = 0;

    if(loc != 2) {
        ret += solve(cur + 1, 1);
    }
    else if(VIP[cur]) return 0;

    if(cur - 1 > 0 && loc != 1) {
        ret += solve(cur + 1, 0);
    }

    if(cur + 1 <= N) {
        ret += solve(cur + 1, 2);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> N;
    arr.resize(N+1);
    int M;
    cin >> M;
    for(int i=0; i<M; i++) {
        int t;
        cin >> t;
        VIP[t] = true;
    }
    cout << solve(1, 1);
}