#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj;
int dis[20004] = {0, };
int sccId[20004] = {0, };
vector<int> sccs;
stack<int> st;
int n = 0, sccCnt = 1;

int tarjan(int cur) {
    dis[cur] = ++n;
    int ret = dis[cur];
    st.push(cur);
    for(int next : adj[cur]) {
        if(!dis[next]) ret = min(ret, tarjan(next));
        if(!sccId[next]) ret = min(ret, dis[next]);
    }

    if(ret == dis[cur]) {
        while(true) {
            int t = st.top();
            st.pop();
            sccId[t] = sccCnt;
            if(t == cur) break;
        }
        sccs.push_back(sccCnt);
        ++sccCnt;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    adj.resize(N*2+2);
    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;  
        int notA, notB;
        if(a<0) {
            a = (-a)*2+1;
            notA = a-1;
        }
        else {
            a = a*2;
            notA = a+1;
        }
        if(b<0) {
            b = (-b)*2+1;
            notB = b-1;
        }
        else {
            b = b*2;
            notB = b+1;
        }
        adj[notA].push_back(b);
        adj[notB].push_back(a);
    }

    for(int i=2; i<=2*N+1; i++) {
        if(dis[i]) continue;
        tarjan(i);
    }

    for(int i=2; i<=2*N; i+=2) {
        if(sccId[i] == sccId[i+1]) {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
}