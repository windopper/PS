#include <bits/stdc++.h>
#include <limits>

using namespace std;
int N, M;
map<int, vector<pair<int, int>>> graph;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
    }

    int dist[N+1];
    int connect[N+1];
    for(int i=1; i<N+1; i++) connect[i] = i;
    fill_n(dist, N+1, numeric_limits<int>::max());
    priority_queue<pair<int, int>> q;

    q.push({0, 1});
    dist[1] = 0;

    while(!q.empty()) {

        int cost = -q.top().first;
        int cur = q.top().second;
        q.pop();
        
        bool isNotRecover = false;
        for(int i=1; i<N+1; i++) {
            if(dist[i] == numeric_limits<int>::max()) {
                isNotRecover = true;
                break;
            }
        }

        if(!isNotRecover) {
            int k = 0;
            for(int i=1; i<N+1; i++) if(connect[i] != i) k++;
            cout << k << "\n";
            for(int i=1; i<N+1; i++) {
                if(connect[i] != i) {
                    cout << i << " " << connect[i] << "\n";
                }
            }
            break;
        }

        if(dist[cur] < cost) continue;

        for(int i=0; i<graph[cur].size(); i++) {
            int nxt = graph[cur][i].first;
            int nxt_cost = graph[cur][i].second;
            int alt = nxt_cost + cost;
            if(alt < dist[nxt]) {
                dist[nxt] = alt;
                cout << nxt << " " << cur << "\n";
                if(nxt < cur) connect[cur] = nxt;
                else connect[nxt] = cur;
                q.push({-alt, nxt});
            }
        }
    }

    for(int i=1; i<N+1; i++) {
        cout << connect[i] << " ";
    }
}