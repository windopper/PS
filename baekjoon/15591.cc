#include <bits/stdc++.h>

using namespace std;
vector<vector<pair<int, int>>> edges;
vector<int> dis;

int solve(int k, int cur, int usado) {
    int ret = 0;
    if(k <= usado) ret = 1;
    for(int i=0; i<edges[cur].size(); i++) {
        int next = edges[cur][i].first;
        int cost = edges[cur][i].second;
        if(dis[next]) continue;
        dis[next] = 1;
        ret += solve(k, next, min(usado, cost));
        dis[next] = 0;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, Q;
    cin >> N >> Q;
    dis.assign(N+1, 0);
    edges.resize(N+1);
    for(int i=0; i<N-1; i++) {
        int p, q, r;
        cin >> p >> q >> r;
        edges[p].push_back({q, r});
        edges[q].push_back({p, r});
    }

    for(int i=0; i<Q; i++) {
        int k, u;
        cin >> k >> u;
        dis[u] = 1;
        cout << solve(k, u, 1000000000) - 1 << '\n';
        dis[u] = 0;
    }
}