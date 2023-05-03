#include <bits/stdc++.h>

using namespace std;
int comb(int, unsigned int, int, int);
int N, P;
vector<vector<int>> costs;
int dp[1<<16][17];

int solve(int cur, unsigned int mask, int cnt) {
    if(cnt >= P) return 0;
    int &ret = dp[mask][cur];
    if(ret != -1) return ret;
    ret = 987654321;
    for(int i=0; i<N; i++) {
        if(i == cur) continue;
        if(!(mask & (1 << i))) {
            ret = min(ret, solve(i, mask | (1 << i), cnt + 1) + costs[cur][i]);
            ret = min(ret, solve(cur, mask | (1 << i), cnt + 1) + costs[cur][i]);
        }
        else ret = min(ret, solve(i, mask, cnt));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    memset(dp, -1, sizeof(dp));
    costs.resize(N, vector<int>(N));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> costs[i][j];
        }
    }
    string st;
    cin >> st;
    unsigned mask = 0;
    int cnt = 0;
    for(int i=0; i<st.size(); i++) {
        if(st[i] == 'Y') {
            mask |= (1 << i);
            ++cnt;
        }
    }

    cin >> P;
    int ret = 987654321;
    for(int i=0; i<N; i++) {
        if(mask & (1 << i)) ret = min(ret, solve(i, mask, cnt));
    }
    if(cnt >= P) ret = 0;
    if(ret == 987654321) ret = -1;
    cout << ret;
}