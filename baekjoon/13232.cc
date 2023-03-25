#include <bits/stdc++.h>

using namespace std;
int D, L;
vector<vector<int>> edges;
stack<int> st;
int isScc[5001];
int dis[5001];
int n = 0;
int ans = 0;

int tarjan(int cur) {
    dis[cur] = ++n;
    int ret = dis[cur];
    st.push(cur);
    for(auto next : edges[cur]) {
        if(!dis[next]) ret = min(ret, tarjan(next));
        if(!isScc[next]) ret = min(ret, dis[next]);
    }

    if(ret == dis[cur]) {
        int cnt = 0;
        while(1) {
            int t = st.top(); st.pop();
            isScc[t] = 1;
            ++cnt;
            if(t == cur) break;
        }
        ans = max(ans, cnt);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> D >> L;
    edges.resize(D+1);
    for(int i=0; i<L; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
    }

    for(int i=1; i<D+1; i++) {
        if(dis[i]) continue;
        tarjan(i);
    }

    cout << ans;
}