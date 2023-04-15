#include <bits/stdc++.h>

using namespace std;
const int MAXN = 804;
const int INF = 987654321;
int source = 802;
int sink = 803;
vector<vector<int>> adj;
int flow[MAXN][MAXN] = {0, };
int capacity[MAXN][MAXN] = {0, };
int cost[MAXN][MAXN] = {0, };

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    adj.resize(MAXN);
    for(int i=401; i<=400+M; i++) {
        adj[i].push_back(sink);
        adj[sink].push_back(i);
        capacity[i][sink] = 1;
    }

    for(int i=1; i<=N; i++) {
        int t;
        cin >> t;
        adj[source].push_back(i);
        adj[i].push_back(source);
        capacity[source][i] = 1;
        while(t--) {
            int num, pay;
            cin >> num >> pay;
            cost[i][num+400] = -pay;
            cost[num+400][i] = pay;

            adj[i].push_back(num+400);
            adj[num+400].push_back(i);
            capacity[i][num+400] = 1;
        }
    }

    int cnt = 0;
    long long ans = 0;
    while(1) {
        vector<int> dis(MAXN, INF);
        vector<int> parent(MAXN, -1);
        vector<int> inQ(MAXN, false);
        queue<int> q;
        q.push(source);
        inQ[source] = 1;
        dis[source] = 0;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            inQ[cur] = false;
            for(int next : adj[cur]) {
                int c = cost[cur][next];
                int alt = c + dis[cur];
                if(capacity[cur][next] - flow[cur][next] > 0 && dis[next] > alt) {
                    dis[next] = alt;
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
            ans += amount * -cost[parent[p]][p];
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        ++cnt;
    }

    cout << cnt << '\n' << ans;
}