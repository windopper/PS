#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> edges;
vector<int> dist;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M, K, X;
    cin >> N >> M >> K >> X;
    edges.resize(N+1);
    dist.assign(N+1, 300000);
    for(int i=0; i<M; i++) {
        int A, B;
        cin >> A >> B;
        edges[A].push_back(B);
    }

    queue<int> pq;
    pq.push(X);
    dist[X] = 0;

    vector<int> arrived;
    while(!pq.empty()) {
        int cur = pq.front();
        pq.pop();

        if(dist[cur] == K) {
            arrived.push_back(cur);
        }
        if(dist[cur] > K) break;

        for(int i=0; i<edges[cur].size(); i++) {
            int nxt = edges[cur][i];
            if(dist[nxt] > dist[cur] + 1) {
                dist[nxt] = dist[cur] + 1;
                pq.push(nxt);
            }
        }
    }

    if(arrived.empty()) cout << -1;
    else {
        sort(arrived.begin(), arrived.end());
        for(int i=0; i<arrived.size(); i++) {
            cout << arrived[i] << '\n';
        }
    }
}