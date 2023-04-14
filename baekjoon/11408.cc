#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj;
vector<vector<int>> flow;
vector<vector<int>> capacity;
int N, P;
int source = 2;
int sink = 5;
const int MAX_N = 2*400 + 10;
const int INF  = 987654321;

int solve() {
    int ret = 0;
    while(1) {
        vector<int> parent(MAX_N, -1);
        queue<int> q;
        q.push(source);
        while(!q.empty() && parent[sink] == -1) {
            int cur = q.front(); q.pop();
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
        ret += amount;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> P;
    adj.resize(MAX_N);
    flow.assign(MAX_N, vector<int>(MAX_N, 0));
    capacity.assign(MAX_N, vector<int>(MAX_N, 0));
    // 정점 분할
    adj[2].push_back(3);
    adj[3].push_back(2);
    capacity[2][3] = INF;
    adj[5].push_back(4);
    adj[4].push_back(5);
    capacity[4][5] = INF;
    for (int i = 3; i <= N; i++) {
        adj[i*2].push_back(i*2+1);
        adj[i*2+1].push_back(i*2);
        capacity[i*2][i*2+1] = 1;
    }

    for(int i=1; i<=P; i++) {
        int a, b;
        cin >> a >> b;
        adj[a*2+1].push_back(b*2);
        adj[b*2].push_back(a*2+1);
        capacity[a*2+1][b*2] = INF;
        adj[b*2+1].push_back(a*2);
        adj[a*2].push_back(b*2+1);
        capacity[b*2+1][a*2] = INF;
    }

    cout << solve();
}