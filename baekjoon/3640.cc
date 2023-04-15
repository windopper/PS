#include <bits/stdc++.h>

using namespace std;
const int MAXN = 2002;
const int INF = 987654321;
int source = 2;
int sink;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int V, E;
    while(cin >> V >> E) {
        sink = V*2+1;
        vector<vector<int>> adj(MAXN);
        vector<vector<int>> flow(MAXN, vector<int>(MAXN, 0));
        vector<vector<int>> capacity(MAXN, vector<int>(MAXN, 0));
        vector<vector<int>> cost(MAXN, vector<int>(MAXN, 0));
        for(int i=0; i<E; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a*2+1].push_back(b*2);
            adj[b*2].push_back(a*2+1);
            capacity[a*2+1][b*2] = 1;
            cost[a*2+1][b*2] = c;
            cost[b*2][a*2+1] = -c;
        }

        adj[2].push_back(3);
        adj[3].push_back(2);
        capacity[2][3] = 2;

        adj[V*2].push_back(sink);
        adj[sink].push_back(V*2);
        capacity[V*2][sink] = 2;

        for(int i=2; i<=V-1; i++) {
            adj[i*2].push_back(i*2+1);
            adj[i*2+1].push_back(i*2);
            capacity[i*2][i*2+1] = 1;
        }

        int cnt = 0;
        int turn = 2;
        while(turn--) {
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
                    int alt = c + dist[cur];
                    if(capacity[cur][next] - flow[cur][next] > 0 && dist[next] > alt) {
                        dist[next] = alt;
                        parent[next] = cur;
                        if(!inQ[next]) {
                            inQ[next] = 1;
                            q.push(next);
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
                cnt += amount * cost[parent[p]][p];
                flow[parent[p]][p] += amount;
                flow[p][parent[p]] -= amount;
            }
        }

        cout << cnt << '\n';
    }
}