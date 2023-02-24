#include <bits/stdc++.h>
#include <limits>

using namespace std;
int n, m;
map<int, vector<pair<int, int>>> graph;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    int s, t;
    cin >> s >> t;

    priority_queue<pair<int, int>> q;
    int dist[n+1];
    fill_n(dist, n+1, 99999999);

    q.push({0, s});
    dist[s] = 0;

    while(!q.empty()) {
        int cost = -q.top().first;
        int cur = q.top().second;
        q.pop();

        if(cur == t) {
            cout << cost;
            break;
        }

        if(dist[cur] < cost) continue;

        for(int i=0; i<graph[cur].size(); i++) {
            int nxt = graph[cur][i].first;
            int nxt_cost = graph[cur][i].second;
            int alt = nxt_cost + cost;
            if(alt < dist[nxt]) {
                dist[nxt] = alt;
                q.push({-alt, nxt});
            }
        }
    }
}