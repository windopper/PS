#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> edges;
int discovered[100001];
int isScc[100001];
int cnt = 0, n = 0;
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
        while(1) {
            int t = st.top();
            st.pop();
            isScc[t] = 1;
            if(t == cur) break;
        }
        ++cnt;
    }

    return ret;
}

using namespace std;
int N, M;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for(; T>0; --T) {
        cin >> N >> M;

        edges.assign(N+1, vector<int>());
        memset(discovered, 0, 100001);
        memset(isScc, 0, 100001);
        cnt = 0;
        n = 0;
        st = stack<int>();

        for(int i=0; i<M; i++) {
            int x, y;
            cin >> x >> y;
            edges[x].push_back(y);
        }

        for(int i=1; i<N+1; i++) {
            if(!discovered[i]) tarjan(i);
        }
        cout << cnt;
    }

}