#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj;
int dis[20004];
int sccId[20004];
int n = 0, sccCnt = 1;
stack<int> st;

int tarjan(int cur) {
    dis[cur] = ++n;
    int ret = dis[cur];
    st.push(cur);

    for(int next : adj[cur]) {
        if(!dis[next]) ret = min(ret, tarjan(next));
        if(!sccId[next]) ret = min(ret, dis[next]);
    }
    if(ret == dis[cur]) {
        while(1) {
            int t = st.top();
            st.pop();
            sccId[t] = sccCnt;
            if(cur == t) break;
        }
        ++sccCnt;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    adj.resize(2*N+2);
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

    for(int i=2; i<=N*2+1; i++) {
        if(dis[i]) continue;
        tarjan(i);
    }

    for(int i=2; i<=N*2; i+=2) {
        if(sccId[i] == sccId[i+1]) {
            cout << 0;
            return 0;
        }
    }

    vector<pair<int, int>> order;
    vector<int> result(2*N+2, -1);

    for(int i=2; i<=2*N+1; i++) {
        order.push_back({-sccId[i], i});
    }
    sort(order.begin(), order.end());

    for(int i=0; i<2*N; i++) {
        int vertex = order[i].second;
        int v = vertex / 2;
        bool isTrue = vertex % 2 == 0;
        if(result[v] != -1) continue;
        result[v] = !isTrue;
    }

    cout << 1 << "\n";

    for(int i=1; i<=N; i++) {
        cout << result[i] << " ";
    }
}