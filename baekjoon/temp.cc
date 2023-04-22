#include <bits/stdc++.h>
#include <cstdint>

using namespace std;
vector<vector<int>> adj;
vector<vector<int>> cost;
vector<vector<int>> capacity;
vector<vector<int>> flow;
const int MAXN = 204;
const int INF = 987654321;
int source = 202, sink = 203;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    adj.resize(MAXN);
    capacity.assign(MAXN, vector<int>(MAXN, 0));
    flow.assign(MAXN, vector<int>(MAXN, 0));
    cost.assign(MAXN, vector<int>(MAXN, 0));
    for(int i=1; i<=N; i++) {
        adj[source].push_back(i);
        adj[i].push_back(source);

        int t;
        cin >> t;
        capacity[source][i] = t;
    }

    for(int i=101; i<=M+100; i++) {
        adj[i].push_back(sink);
        adj[sink].push_back(i);
        int t;
        cin >> t;
        capacity[i][sink] = t;
    }

    for(int i=101; i<=M+100; i++) {
        for(int j=1; j<=N; j++) {
            int c;
            cin >> c;
            adj[j].push_back(i);
            adj[i].push_back(j);
            cost[j][i] = c;
            cost[i][j] = -c;
            capacity[j][i] = INF;
        }
    }

    int ans = 0;

    while(1) {
        vector<int> dis(MAXN, INF);
        vector<bool> inQ(MAXN, false);
        vector<int> parent(MAXN, -1);
        queue<int> q;
        q.push(source);
        inQ[source] = 1;
        dis[source] = 0;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            inQ[cur] = 0;
            for(int next : adj[cur]) {
                if(capacity[cur][next] - flow[cur][next] > 0 && dis[next] > dis[cur] + cost[cur][next]) {
                    dis[next] = dis[cur] + cost[cur][next];
                    parent[next] = cur;
                    if(!inQ[next]) {
                        q.push(next);
                        inQ[next] = 1;
                    }
                }
            }
        }
        if (parent[sink] == -1) break;
        int amount = INF;
        for (int p = sink; p != source; p = parent[p]) {
          amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
        }

        for (int p = sink; p != source; p = parent[p]) {
          ans += cost[parent[p]][p] * amount;
          flow[parent[p]][p] += amount;
          flow[p][parent[p]] -= amount;
        }
    }

    cout << ans;
}