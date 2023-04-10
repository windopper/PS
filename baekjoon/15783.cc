#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj;
stack<int> st;
int sccId[100001];
int dis[100001];
int disCnt = 0, sccCnt = 1;

int tarjan(int start, int cur) {
    dis[cur] = ++disCnt;
    cout << "vis:" << cur << "\n";
    int ret = dis[cur];
    st.push(cur);
    for(int next : adj[cur]) {
        if(!dis[next]) ret = min(ret, tarjan(start, next));
        if(!sccId[next]) ret = min(ret, dis[next]);
    }

    if(adj[cur].size() == 0) {
        if(start == cur) {
            ++sccCnt;
        }
        cout << cur << " ";
        return dis[start];
    }

    if(ret == dis[cur]) {
        while(1) {
            int t = st.top();
            st.pop();
            sccId[t] = sccCnt;
            if(t == cur) break;
        }
        //cout << cur << "\n";
        ++sccCnt;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    adj.resize(N+1);
    vector<int> indegree(N+1, 0);
    for(int i=0; i<M; i++) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        indegree[B]++;
    }

    for(int i=0; i<N; i++) {
        if(dis[i]) continue;
        if(indegree[i]) continue;
        tarjan(i, i);
    }

    cout << sccCnt-1;
}