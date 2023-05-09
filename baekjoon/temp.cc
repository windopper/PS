#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> g;
vector<int> vis1;
vector<int> vis2;
unordered_map<int, bool> isGates;
int minVal = numeric_limits<int>::max();

int solve(int cur, int summit, bool done, int intensity) {
    if(!done && isGates[cur]) {
        done = true;
    }
    if(done && cur == summit) {
        return intensity;
    }

    int ret = numeric_limits<int>::max();
    for(pair<int ,int> next : g[cur]) {
        if(isGates[next.first] && summit != next.first) continue;
        if(!done && vis1[next.first]) continue;
        if(done && vis2[next.first]) continue;
        if(!done) vis1[next.first] = 1;
        if(done) vis2[next.first] = 1;
        if(minVal <= next.second) continue;
        ret = min(ret, solve(next.first, summit, done, max(intensity, next.second)));
        if(!done) vis1[next.first] = 0;
        if(done) vis2[next.first] = 0;
    }
    return ret;
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    g.resize(10001);
    vis1.assign(10001, 0);
    vis2.assign(10001, 0);
    for(vector<int> p : paths) {
        g[p[0]].push_back({p[1], p[2]});
        g[p[1]].push_back({p[0], p[2]});
    }

    for(int gate : gates) {
        isGates[gate] = true;
    }

    vector<int> answer(2);
    for (int s : summits) {
        int val = solve(s, s, false, 0);
        if (minVal > val) {
            minVal = val;
            answer[0] = s;
            answer[1] = val;
        }
        cout << s << " " << val << '\n';
    }
    return answer;
}