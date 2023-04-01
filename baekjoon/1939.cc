#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<pair<int, int>>> edges;

bool pass(int cur, int target, int weight) {
    queue<int> q;
    vector<int> visited(N+1, 0);
    q.push(cur);
    while(!q.empty()) {
        int t = q.front();
        q.pop();
        if(visited[t]) continue;
        visited[t] = 1;
        if(t == target) return true;
        for(int i=0; i<edges[t].size(); i++) {
            int next = edges[t][i].first;
            int nextCost = edges[t][i].second;
            if(weight > nextCost) continue;
            q.push(next);
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    edges.resize(N+1);
    for(int i=0; i<M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }

    int a, b;
    cin >> a >> b;
    
    int s = 1;
    int e = 1000000000;
    int ans = 0;
    while(s<=e) {
        int m = (s+e)/2;
        bool status = pass(a, b, m);
        if(status) {
            ans = m;
            s = m+1;
        }
        else {
            e = m-1;
        }
    }

    cout << ans;
}