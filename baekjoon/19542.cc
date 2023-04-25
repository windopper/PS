#include <bits/stdc++.h>

using namespace std;
int N, S, D;
vector<vector<int>> adj;
int dep[100001] = {0, };

int depth(int cur, int post) {
    int& ret = dep[cur];
    for(int next : adj[cur]) {
        if(next == post) continue;
        ret = max(ret, depth(next, cur));
    }
    ret += 1;
    return ret;
}

int dfs(int cur, int post) {
    int ret = 0;
    int vis = 0;
    bool isMoved = false;
    for(int next : adj[cur]) {
        if(next == post) continue;
        if(dep[next] <= D) continue;
        ret += dfs(next, cur) + 1;
        ++vis;
        isMoved = true;
    }
    if(!isMoved) ret = 0;
    ret += vis;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> S >> D;
    adj.resize(N+1);
    for(int i=0; i<N-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    depth(S, S);
    cout << dfs(S, S);
}