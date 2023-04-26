#include <bits/stdc++.h>

using namespace std;
int N, K, D;

const int INF = 304;

vector<vector<int>> capacity(INF, vector<int>(INF, 0));
vector<vector<int>> flow(INF, vector<int>(INF, 0));
vector<vector<int>> adj(INF);
int sink = 302, source = 303;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K >> D;
    for(int i=1; i<=D; i++) {
        int t; cin >> t;
        adj[source].push_back(i);
        adj[i].push_back(source);
        capacity[source][i] = t;
    }
    for(int i=101; i<=N+100; i++) {
        int z;
        cin >> z;
        adj[i].push_back(sink);
        adj[sink].push_back(i);
        capacity[i][sink] = min(K, z);
        for(int j=0; j<z; j++) {
            int t;
            cin >> t;
            adj[t].push_back(i);
            adj[i].push_back(t);
            capacity[t][i] = 1;
        }
    }

    int ans = 0;

    while(1) {
        vector<int> parent(INF, -1);
        queue<int> q;
        q.push(source);
        while(!q.empty() && parent[sink] == -1) {
            int cur = q.front();
            q.pop();
            for(int next : adj[cur]) {
                if(capacity[cur][next] - flow[cur][next] > 0 && parent[next] == -1) {
                    parent[next] = cur;
                    q.push(next);
                }
            }
        }
        if(parent[sink] == -1) break;
        int amount = 987654321;
        for(int p = sink; p != source; p = parent[p]) {
            amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
        }
        ans += amount;
        for(int p = sink; p != source; p = parent[p]) {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
    }

    cout << ans;
}