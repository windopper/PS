#include <bits/stdc++.h>
#include <limits>

using namespace std;
int T, N, M;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    for(int t=1; t<T+1; t++) {
        cin >> N >> M;

        map<int, vector<pair<int, int>>> graph;

        for(int i=0; i<N; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            graph[x].push_back({y, z});
            graph[y].push_back({x, z});
        }

        int dist[M];
        int path[M];
        fill_n(dist, M, 99999999);
        for(int i=0; i<M; i++) path[i] = i;
        priority_queue<pair<int, int>> q;
        bool isMeet = false;

        q.push({0, 0});
        dist[0] = 0;

        while(!q.empty()) {

            int cost = -q.top().first;
            int cur = q.top().second;
            q.pop();

            if(cur == M-1) {
                isMeet = true;
                int point = M-1;
                vector<int> tmp;
                cout << "Case #" << t << ": ";
                while(point != 0) {
                    tmp.push_back(point);
                    point = path[point];
                }
                tmp.push_back(point);
                reverse(tmp.begin(), tmp.end());
                for(int i=0; i<tmp.size(); i++) {
                    cout << tmp[i] << " ";
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
                    path[nxt] = cur;
                    q.push({-alt, nxt});
                }
            }
        }

        if(!isMeet) {
            cout << "Case #" << t << ": " << -1;
        }
        cout << "\n";
    }
}