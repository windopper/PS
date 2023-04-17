#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> capacity;
vector<vector<int>> flow;
const int INF = 987654321;
const int MAXN = 1003;
int n;
int sink = 1001;
int source = 1002;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        vector<vector<int>> adj(MAXN);
        vector<vector<int>> time(MAXN, vector<int>(MAXN));
        flow.clear();
        capacity.clear();
        flow.assign(MAXN, vector<int>(MAXN, 0));
        capacity.assign(MAXN, vector<int>(MAXN, 0));
        int I, G, S;
        cin >> I >> G >> S;

        adj[source].push_back(I);
        adj[I].push_back(source);
        capacity[source][I] = G;
        time[source][I] = 0;

        int M;
        cin >> M;
        for(int i=0; i<M; i++) {
            int t;
            cin >> t;
            adj[t].push_back(sink);
            adj[sink].push_back(t);
            capacity[t][sink] = INF;
            time[t][sink] = 0;
        }
        int R;
        cin >> R;
        for(int i=0; i<R; i++) {
            int a, b, p, t;
            cin >> a >> b >> p >> t;
            adj[a].push_back(b);
            adj[b].push_back(a);
            capacity[a][b] = p;
            time[a][b] = t;
        }

        int ans = 0;
        int timeRemain = S;
        while(1) {
            vector<int> parent(MAXN, -1);
            parent[source] = source;
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
        }
    }
}