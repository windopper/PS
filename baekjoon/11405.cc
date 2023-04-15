#include <bits/stdc++.h>

using namespace std;
const int INF = 987654321;
const int MAXN = 303;
int source = 301;
int sink = 302;
vector<vector<int>> cost;
vector<vector<int>> adj;
vector<vector<int>> flow;
vector<vector<int>> capacity;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    adj.resize(MAXN, vector<int>(MAXN));
    flow.assign(MAXN, vector<int>(MAXN, 0));
    capacity.assign(MAXN, vector<int>(MAXN, 0));
    cost.assign(MAXN, vector<int>(MAXN, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 100 + 1; j <= M + 100; j++) {
            adj[j].push_back(i);
            adj[i].push_back(j);
            capacity[j][i] = INF;
        }
    }

    for (int i = 1; i <= N; i++) {
        int t;
        cin >> t;
        adj[i].push_back(sink);
        adj[sink].push_back(i);
        capacity[i][sink] = t;
    }

    for (int j = 100 + 1; j <= M + 100; j++) {
        int t;
        cin >> t;
        adj[source].push_back(j);
        adj[j].push_back(source);
        capacity[source][j] = t;
    }

    for (int i = 100 + 1; i <= 100 + M; i++) {
        for (int j = 1; j <= N; j++) {
            int t;
            cin >> t;
            cost[i][j] = t;
            cost[j][i] = -t;
        }
    }

    int ans = 0;

    while (1) {
        vector<int> dist(MAXN, INF);
        vector<int> parent(MAXN, -1);
        vector<bool> inQ(MAXN, false);
        queue<int> q;
        dist[source] = 0;
        q.push(source);
        inQ[source] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            inQ[cur] = false;
            for (int next : adj[cur]) {
                int c = cost[cur][next];
                int alt = dist[cur] + c;
                if (capacity[cur][next] - flow[cur][next] > 0 && dist[next] > alt) {
                    dist[next] = alt;
                    parent[next] = cur;
                    if(!inQ[next]) {
                        q.push(next);
                        inQ[next] = true;
                    }
                }
            }
        }

        if(parent[sink] == -1) break;
        int amount = INF;
        for(int p = sink; p != source; p = parent[p]) {
            amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
        }

        for(int p = sink; p != source; p = parent[p]) {
            ans += cost[parent[p]][p] * amount;
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
    }

    cout << ans;
}