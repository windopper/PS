#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> g;
vector<int> vis;
vector<bool> isGates(50001);
vector<bool> isSummit(50001);
int minVal = numeric_limits<int>::max();
vector<int> answer(2, 987654321);

void solve(vector<int>& gates) {
    priority_queue<pair<int, int>> pq;
    vis.assign(50001, 987654321);
    for (int gate : gates) {
        pq.push({0, gate});
        vis[gate] = 0;
    }
    while (!pq.empty()) {
        int w = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (minVal < w) {
            break;
        }
        if (isSummit[cur]) {
            if (minVal > w) {
                minVal = w;
                answer[0] = cur;
                answer[1] = w;
            } else if (minVal == w && answer[0] > cur) {
                answer[0] = cur;
            }
        }
        if (vis[cur] < w || isSummit[cur]) continue;
        for (pair<int, int> next : g[cur]) {
            int alt = max(w, next.second);
            if (minVal < alt) continue;
            if (vis[next.first] > alt) {
                vis[next.first] = alt;
                pq.push({alt, next.first});
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    g.resize(50001);
    for (vector<int> p : paths) {
        g[p[0]].push_back({p[1], p[2]});
        g[p[1]].push_back({p[0], p[2]});
    }
    for (int gate : gates) {
        isGates[gate] = true;
    }
    for (int summit : summits) {
        isSummit[summit] = true;
    }
    solve(gates);
    return answer;
}