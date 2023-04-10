#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj;
int aMatch[401];
int bMatch[401];
int dis[401];

bool bipartite(int cur) {
    cout << cur << "-> ";
    if(dis[cur]) return false;
    dis[cur] = true;
    for(int next : adj[cur]) {
        if(next == 2) return true;
        if(bMatch[next] == -1 || bipartite(bMatch[next])) {
            bMatch[next] = cur;
            aMatch[cur] = next;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, P;
    cin >> N >> P;
    adj.resize(N+1);
    for(int i=0; i<P; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int ans = 0;
    memset(aMatch, -1, sizeof(aMatch));
    memset(bMatch, -1, sizeof(bMatch));
    for(int i=0; i<adj[1].size(); i++) {
        memset(dis, 0, sizeof(dis));
        if(bipartite(adj[1][i])) ++ans;
        cout << '\n';
    }

    cout << ans;
}