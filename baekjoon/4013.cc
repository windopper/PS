#include <bits/stdc++.h>

using namespace std;
int N, M, S, P;
vector<vector<int>> edges;
vector<int> rest;
int money[500001];
int dis[500001];
int sccId[500001];
stack<int> st;
vector<int> prices;
int n = 0;

int visited[500001];
int visitedScc[500001];
int ans = 0;

int tarjan(int cur) {
    dis[cur] = ++n;
    int ret = dis[cur];
    st.push(cur);
    for(auto next : edges[cur]) {
        if(!dis[next]) ret = min(ret, tarjan(next));
        if(!sccId[next]) ret = min(ret, dis[next]);
    }
    if(ret == dis[cur]) {
        int priceSum = 0;
        while(1) {
            int t = st.top();
            st.pop();
            priceSum += money[t];
            sccId[t] = prices.size() + 1;
            if(t == cur) break;
        }
        prices.push_back(priceSum);
    }

    return ret;
}

void solve(int cur, int p) {
    if(visited[cur]) return;
    visited[cur] = 1;
    if(!visitedScc[sccId[cur]]) {
        p += prices[sccId[cur]-1];
        visitedScc[sccId[cur]] = 1;
    }

    for(int r : rest) {
        if(r == cur) {
            ans = max(ans, p);
            break;
        }
    }

    for(int next : edges[cur]) {
        solve(next, p);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    edges.resize(N+1);
    for(int i=0; i<M; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
    }
    for(int i=1; i<N+1; i++) {
        cin >> money[i];
    }

    cin >> S >> P;
    for(int i=0; i<P; i++) {
        int temp;
        cin >> temp;
        rest.push_back(temp);
    }

    for(int i=1; i<N+1; i++) {
        if(dis[i]) continue;
        tarjan(i);
    }

    solve(S, 0);

    cout << ans;

}