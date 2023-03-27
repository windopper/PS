#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<vector<int>> graph;
int dis[5001];
int sccId[5001];
stack<int> st;
vector<vector<int>> sccs;
int l = 0, sccCnt = 1;

int tarjan(int cur) {
    dis[cur] = ++l;
    int ret = dis[cur];
    st.push(cur);
    for(int next : graph[cur]) {
        if(!dis[next]) ret = min(ret, tarjan(next));
        if(!sccId[next]) ret = min(ret, dis[next]);
    }

    if(ret == dis[cur]) {
        vector<int> cycle;
        while(1) {
            int t = st.top();
            st.pop();
            cycle.push_back(t);
            sccId[t] = sccCnt;
            if(t == cur) break;
        }
        ++sccCnt;
        sccs.push_back(cycle);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(1) {
        cin >> n;
        if(n == 0) return 0;
        cin >> m;
        memset(dis, 0, sizeof(dis));
        memset(sccId, 0, sizeof(sccId));
        l = 0; sccCnt = 1;
        sccs.clear();
        graph.assign(n+1, vector<int>());
        for(int i=0; i<m; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
        }

        for(int i=1; i<n+1; i++) {
            if(dis[i]) continue;
            tarjan(i);
        }

        int outdegree[5001] = {0, };
        for(int i=1; i<n+1; i++) {
            for(int next : graph[i]) {
                if(sccId[next] != sccId[i]) {
                    ++outdegree[sccId[i]];
                }
            }
        }

        vector<int> list;
        for(int i=1; i<sccCnt; i++) {
            if(outdegree[i] == 0) {
                for(int node : sccs[i-1]) {
                    list.push_back(node);
                }
            }
        }

        sort(list.begin(), list.end());
        for(int node : list) {
            cout << node << " ";
        }

        cout << "\n";
    }
}