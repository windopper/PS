#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> edges;
int dis[100001];
int isScc[100001];
stack<int> st;
int n = 0;

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
            isScc[t] = 1;
            cycle.push_back(t);
            if(t == cur) break;
        }
        sort(cycle.begin(), cycle.end());
        for(auto c : cycle) {
            cout << c << " ";
        }
        cout << "\n";
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
}