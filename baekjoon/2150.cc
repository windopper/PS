#include <bits/stdc++.h>

using namespace std;
int V, E;
vector<vector<int>> edges;
int n = 0, cnt = 0;
int discovered[10001];
int isScc[10001];
vector<vector<int>> sccs;
stack<int> st;

int tarjan(int cur) {
    discovered[cur] = ++n;
    int ret = discovered[cur];
    st.push(cur);
    for(int i=0; i<edges[cur].size(); i++) {
        int nxt = edges[cur][i];
        if(!discovered[nxt]) {
            ret = min(ret, tarjan(nxt));
        }
        if(!isScc[nxt]) {
            ret = min(ret, discovered[nxt]);
        }
    }

    if(ret == discovered[cur]) {
        vector<int> tmp;
        while(true) {
            int t = st.top();
            st.pop();
            isScc[t] = 1;
            tmp.push_back(t);
            if(t == cur) break;
        }
        sort(tmp.begin(), tmp.end());
        sccs.push_back(tmp);
        ++cnt;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> V >> E;
    edges.resize(V+1);
    for(int i=0; i<E; i++) {
        int A, B; 
        cin >> A >> B;
        edges[A].push_back(B);
    }

    for(int i=1; i<V+1; i++) {
        if(!discovered[i]) tarjan(i);
    }
    cout << cnt << "\n";
    sort(sccs.begin(), sccs.end());
    for(int i=0; i<sccs.size(); i++) {
        for(int j=0; j<sccs[i].size(); j++) {
            cout << sccs[i][j] << " ";
        }
        cout << -1 << "\n";
    }
}