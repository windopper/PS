#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> w;
vector<int> ans;
vector<vector<int>> g;
int dp[10001][2];

int solve(int cur, int has, int post) {
    int &ret = dp[cur][has];
    if(ret != -1) return ret;
    if(has) ret = w[cur];
    else ret = 0;
    for(int next : g[cur]) {
        if(next == post) continue;
        if(has) ret += solve(next, 0, cur);
        else ret += max(solve(next, 0, cur), solve(next, 1, cur));
    }
    return ret;
}

void track(int cur, int has, int post) {
    if(has) {
        ans.push_back(cur);
        for(auto next : g[cur]) {
            if(next == post) continue;
            track(next, 0, cur);
        }
    }
    else {
        for(auto next : g[cur]) {
            if(next == post) continue;
            if(dp[next][1] > dp[next][0]) {
                track(next, 1, cur);
            }
            else {
                track(next, 0, cur);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    w.resize(n+1);
    memset(dp, -1, sizeof(dp));
    for(int i=1; i<=n; i++) {
        cin >> w[i];
    }
    g.resize(n+1);
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int t1 = solve(1, 0, -1);
    int t2 = solve(1, 1, -1);
    if(t1 > t2) {
        track(1, 0, -1);
    }
    else {
        track(1, 1, -1);
    }
    sort(ans.begin(), ans.end());
    cout << max(t1, t2) << '\n';

    for(auto next : ans) cout << next << " ";
}