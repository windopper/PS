#include <bits/stdc++.h>

using namespace std;
int N, D;
priority_queue<pair<int, int>> q;
map<int, vector<pair<int, int>>> graph;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> D;
    for(int i=0; i<N; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        graph[s].push_back({c, e});
    }

    for(int i=0; i<graph[0].size(); i++) {
        q.push(graph[0][i]);
    }

    int dist[12] = {100000000, };
    int visited[12] = {0, };

    while(!q.empty()) {
        
        int cost = q.top().first;
        int cur = q.top().second;

        if(visited[cur] == 1) continue;
        for(int i=0; i<graph[cur].size(); i++) {
            int nxt = graph[cur][i].first;
            int nxt_cost = graph[cur][i].second;
            
        }
    }
}