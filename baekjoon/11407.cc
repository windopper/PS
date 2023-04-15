#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj;
vector<vector<int>> flow;
vector<vector<int>> capacity;
vector<vector<int>> cost;
const int MAXN = 203;
const int INF = 987654321;
int source = 201, sink = 202;
int N, M;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    flow.assign(MAXN, vector<int>(MAXN, 0));
    capacity.assign(MAXN, vector<int>(MAXN, 0));
    cost.resize(MAXN, vector<int>(MAXN));
    adj.resize(MAXN);

    for(int i=1; i<=N; i++) {
        int t;
        cin >> t;
        adj[source].push_back(i);
        adj[i].push_back(source);
        capacity[source][i] = t;
    }

    for(int i=101; i<=100+M; i++) {
        int t; cin >> t;
        adj[i].push_back(sink);
        adj[sink].push_back(i);
        capacity[i][sink] = t;
    }

    for(int i=101; i<=100+M; i++) {
        for(int j=1; j<=N; j++) {
            int t;
            cin >> t;
            adj[j].push_back(i);
            adj[i].push_back(j);
            capacity[j][i] = t;
        }
    }

    for(int i=101; i<=100+M; i++) {
        for(int j=1; j<=N; j++) {
            int t; cin >> t;
            cost[j][i] = t;
            cost[i][j] = -t;
        }
    }

    int cnt = 0;
    long long ans = 0;

    while(1) {
        vector<int> dist(MAXN, INF);
        vector<int> parent(MAXN, -1);
        vector<int> inQ(MAXN, 0);
        queue<int> q;
        q.push(source);
        inQ[source] = 1;
        dist[source] = 0;
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            inQ[cur] = 0;
            for(int next : adj[cur]) {
                int c = cost[cur][next];
                int alt = dist[cur] + c;
                if(capacity[cur][next] - flow[cur][next] > 0 && dist[next] > alt) {
                    dist[next] = alt;
                    parent[next] = cur;
                    if(!inQ[next]) {
                        q.push(next);
                        inQ[next] = 1;
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
            ans += amount * cost[parent[p]][p];
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        cnt += amount;
    }

    cout << cnt << '\n' << ans;
}