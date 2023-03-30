#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> edges;
int times[100001];
int indegree[100001] = {0, };
int dp[100001];

int solve(int cur) {
    int &ret = dp[cur];
    if(ret != -1) return ret;
    ret = 0;
    for(int next : edges[cur]) {
        ret = max(ret, solve(next) + times[cur]);
    }
    if(ret == 0) ret = times[cur];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    edges.resize(N+1);
    for(int i=1; i<N+1; i++) {
        cin >> times[i];
        while(1) {
            int nec;
            cin >> nec;
            if(nec == -1) break;
            edges[i].push_back(nec);
            ++indegree[nec];
        }
    }

    memset(dp, -1, sizeof(dp)); 
    for(int i=1; i<N+1; i++) {
        if(indegree[i] == 0) solve(i);
    }

    for(int i=1; i<=N; ++i) {
        cout << dp[i] << "\n";
    }
}