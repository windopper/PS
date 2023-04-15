#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100000;
vector<vector<pair<int, int>>> adj;
int N;
const int INF = 987654321;
int spfa(int start) {
    vector<int> dist(MAXN, INF);
    vector<int> cycle(MAXN, 0);
    vector<bool> inQ(MAXN, false);
    queue<int> q;
    q.push(start);
    inQ[start] = true;
    dist[start] = 0;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        inQ[cur] = false;
        for(pair<int, int> p : adj[cur]) {
            int next = p.first;
            int cost = p.second;
            int alt = cost + dist[cur];
            if(dist[next] > alt) {
                dist[next] = alt;
                if(!inQ[next]) {
                    cycle[next]++;
                    if(cycle[next] >= N) {
                        return -1; // find cycle
                    }
                    q.push(next);
                    inQ[next] = true;
                }
            }
        }
    }
}