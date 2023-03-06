#include <bits/stdc++.h>

using namespace std;
int N;
vector<vector<int>> graph;

int solve(vector<int>& dist, int cur, int past, int d) {
    if(dist[cur] != -1) return dist[cur];
    dist[cur] = d;
    int res = -1;
    for(int i=0; i<graph[cur].size(); i++) {
        if(past == graph[cur][i]) continue;
        res = solve(dist, graph[cur][i], cur, d+1);
        if(res >= 0) return res;
    }   
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    graph.resize(N+1);
    for(int i=0; i<N; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=1; i<N+1; i++) {
        vector<int> dist(N+1, -1);
        int res = solve(dist, i, i, 0);
        if(res != -1) cout << res << " ";
        else cout << 0 << " ";
    }
}