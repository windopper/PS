#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> edges;
vector<vector<int>> sccs;
int dis[1000001];
int isScc[1000001];
stack<int> st;
int n = 0, sccId = 1;

int indegree[1000001];

int tarjan(int cur) {
    dis[cur] = ++n;
    int ret = dis[cur];
    st.push(cur);
    for(auto next : edges[cur]) {
        if(!dis[next]) ret = min(ret, tarjan(next));
        if(!isScc[next]) ret = min(ret, dis[next]);
    }
    if(ret == dis[cur]) {
        vector<int> cycle;
        while(1) {
            int t = st.top(); st.pop();
            isScc[t] = sccId;
            cycle.push_back(t);
            if(t == cur) break;
        }
        sccs.push_back(cycle);
        ++sccId;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    edges.resize(N+1);
    for(int i=0; i<M; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
    }

    for(int i=1; i<N+1; i++) {
        if(dis[i]) continue;
        tarjan(i);
    }

    for(int i=1; i<N+1; i++) {
        for(int next : edges[i]) {
            if(isScc[i] != isScc[next]) {
                ++indegree[isScc[next]];
            }
        }
    }

    int cnt = 0;
    for(int i=1; i<=sccs.size(); i++) {
        if(indegree[i] == 0) ++cnt;
    }

    if(cnt == 1) {
        vector<int> temp = sccs.back();
        sort(temp.begin(), temp.end());
        cout << temp.size() << "\n";
        for(int next : temp) cout << next << " ";
    }
    else {
        cout << 0;
    }

}