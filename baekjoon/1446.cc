#include <bits/stdc++.h>
#include <functional>
#include <limits>

using namespace std;
int N, D;
priority_queue<pair<int, int>> q;
vector<int[3]> graph;
vector<int> nodes;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> D;
    for(int i=0; i<N; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        if(e > D) continue;
        graph.push_back({s, e, c});
    }


    int dist[10000];
    fill_n(dist, 10000, numeric_limits<int>::max());
    int visited[12] = {0, };

    q.push({0, 0});
    dist[0] = 0;

    while(!q.empty()) {
        
        int cost = -q.top().first;
        int cur = q.top().second;
        q.pop();

        if(cur == D) {
            cout << cost;
            break;
        }

        if(cur > D) {
            continue;
        }

        for(int i=0; i<graph.size(); i++) {
            int s = graph[i][0];
            int e = graph[i][1];
            int nxt_cost = graph[i][2];
            if(s < cur) continue;
            int alt = s - cur + nxt_cost + cost;
            if(alt < dist[e]) {
                dist[e] = alt;
                q.push({-alt, e});
            }
        }
    }

}