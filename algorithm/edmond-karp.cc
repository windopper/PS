#include <bits/stdc++.h>

using namespace std;
const int INF = 987654321;
int V;

const int MAX_V = numeric_limits<int>::max();

int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];

int networkflow(int source, int sink) {
    memset(flow, 0, sizeof(flow));
    int totalFlow = 0;
    while(1) {
        vector<int> parent(MAX_V, -1);
        queue<int> q;
        q.push(source);
        while(!q.empty() && parent[sink] == -1) {
            int here = q.front(); q.pop();
            for(int there=0; there<V; ++there) {
                if(capacity[here][there] - flow[here][there] > 0 &&
                    parent[there] == -1) {
                        q.push(there);
                        parent[there] = here;
                }
            }
        }
        if(parent[sink] == -1) break;
        int amount = INF;
        for(int p = sink; p != source; p = parent[p])
            amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
        for(int p = sink; p != source; p = parent[p]) {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        totalFlow += amount;
    }
    return totalFlow;
}