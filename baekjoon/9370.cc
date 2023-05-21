#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
const int INF = 987654321;
int n, m, t, s, g, h;
vector<int> goals;
vector<vector<pair<int, int>>> adj;

void solve(int start, vi& dis) {
    priority_queue<pair<int ,int>> pq;
    pq.push({0, start});
    dis[start] = 0;
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(dis[cur] < cost) continue;
        for(auto nxt : adj[cur]) {
            int next = nxt.first;
            int d = nxt.second;
            int alt = cost + d;
            if(dis[next] > alt) {
                dis[next] = alt;
                pq.push({-alt, next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m >> t >> s >> g >> h;
        adj.clear();
        goals.clear();
        adj.resize(2001);
        for(int i=0; i<m; i++) {
            int a, b, d;
            cin >> a >> b >> d;
            adj[a].push_back({b, d});
            adj[b].push_back({a, d});
        }
        for(int i=0; i<t; i++) {
            int x;
            cin >> x;
            goals.push_back(x);
        }

        vector<int> disS(2001, INF);
        vector<int> disG(2001, INF);
        vector<int> disH(2001, INF);
        solve(s, disS);
        solve(g, disG);
        solve(h, disH);
        int dist_g_h = disG[h];
        sort(goals.begin(), goals.end());
        for(auto goal : goals) {
            if(disS[goal] == disS[g] + dist_g_h + disH[goal]) cout << goal << " ";
            else if(disS[goal] == disS[h] + dist_g_h + disG[goal]) cout << goal << " ";
        }
        cout << '\n';
    }
}