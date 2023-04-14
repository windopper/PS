#include <bits/stdc++.h>

using namespace std;
const int INF = 987654321;
int N, M, K;
vector<vector<int>> capacity;
vector<vector<int>> flow;
vector<vector<int>> adj;
int source = 2001, sink = 2003, bridge = 2002;



int solve() {
    flow.assign(2004, vector<int>(2004, 0));
    int totalFlow = 0;
    while(1) {
        vector<int> parent(2004, -1);
        queue<int> q;
        q.push(source);
        while(!q.empty() && parent[sink] == -1) {
            int cur = q.front();
            q.pop();
            for(int next : adj[cur]) {
                if(capacity[cur][next] - flow[cur][next] > 0 &&
                    parent[next] == -1) {
                    parent[next] = cur;
                    q.push(next);
                }
            }
        }
        if(parent[sink] == -1) break;
        int amount = INF;
        for(int p = sink; p != source; p = parent[p]) {
            amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
        }
        for(int p = sink; p != source; p = parent[p]) {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        totalFlow += amount;
    }
    return totalFlow;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
    capacity.resize(2004, vector<int>(2004, 0));
    flow.resize(2004, vector<int>(2004, 0));
    adj.resize(2004);
    
    for(int i=1; i<N+1; i++) {
        int t;
        cin >> t;
        adj[source].push_back(i);
        adj[i].push_back(source);
        adj[bridge].push_back(i);
        adj[i].push_back(bridge);
        capacity[source][i] = 1;
        capacity[bridge][i] = 1;

        for(int j=0; j<t; j++) {
            int l;
            cin >> l;
            capacity[i][1000+l] = 1;
            adj[i].push_back(1000+l);
            adj[1000+l].push_back(i);
        }
    }

    adj[source].push_back(bridge);
    adj[bridge].push_back(source);
    capacity[source][bridge] = K;

    for(int i=1; i<=M; i++) {
        adj[1000+i].push_back(sink);
        adj[sink].push_back(1000+i);
        capacity[1000+i][sink] = 1;
    }

    cout << solve();
}