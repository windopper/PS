#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<vector<int>> edges;
int dis[100001];
int sccId[100001];
stack<int> st;
int k = 0, sccCnt = 1;

int tarjan(int cur) {
    dis[cur] = ++k;
    int ret = dis[cur];
    st.push(cur);
    for(int next : edges[cur]) {
        if(!dis[next]) ret = min(ret, tarjan(next));
        if(!sccId[next]) ret = min(ret, dis[next]);
    }

    if(ret == dis[cur]) {
        while(1) {
            int t = st.top();
            st.pop();
            sccId[t] = sccCnt;
            if(t == cur) break;
        }
        ++sccCnt;
    }

    return ret;

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    edges.resize(n+1);
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
    }

    for(int i=1; i<n+1; i++) {
        if(dis[i]) continue;
        tarjan(i);
    }

    int indegree[100001] = {0, };
    for(int i=1; i<n+1; i++) {
        for(int next : edges[i]) {
            if(sccId[next] != sccId[i]) {
                ++indegree[sccId[next]];
            }
        }
    }

    int ans = 0;

    for(int i=1; i<sccCnt; i++) {
        if(indegree[i] == 0) ++ans;
    }

    cout << ans;
}