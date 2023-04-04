#include <bits/stdc++.h>

using namespace std;
int N, M, S, T;
vector<vector<int>> adj;
vector<int> arr = {0};
int dis[10001];
int sccId[10001] = {0, };
int n = 0, sccCnt = 1;
stack<int> st;
vector<vector<int>> sccadj(10001);
vector<int> visited(10001, 0);
int dp[10001];

int tarjan(int cur) {
    dis[cur] = ++n;
    int ret = dis[cur];
    st.push(cur);
    for(int next : adj[cur]) {
        if(!dis[next]) ret = min(ret, tarjan(next));
        if(!sccId[next]) ret = min(ret, dis[next]);
    }

    if(ret == dis[cur]) {
        int cnt = 0;
        while(1) {
            int t = st.top();
            st.pop();
            sccId[t] = sccCnt;
            ++cnt;
            if(t == cur) break;
        }
        arr.push_back(cnt);
        ++sccCnt;
    }
    return ret;
}

int solve(int cur, int target) {
    visited[cur] = 1;
    if(cur == target) return arr[target];
    int &ret = dp[cur];
    if(ret != -1) return ret;
    ret = 0;
    for(int next : sccadj[cur]) {
        ret = max(ret, solve(next, target) + arr[cur]);
    }
    return ret;
}

int main()  {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> S >> T;
    adj.resize(N+1);
    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i=1; i<=N; i++) {
        if(dis[i]) continue;
        tarjan(i);
    }

    
    for(int i=1; i<=N; i++) {
        for(int next : adj[i]) {
            if(sccId[i] != sccId[next]) {
                // bool has = false;
                // for(int k : sccadj[sccId[i]]) {
                //     if(k == sccId[next]) has = true;
                //     if(has) break;
                // }
                // if(has) continue;
                sccadj[sccId[i]].push_back(sccId[next]);
            }
        }
    }
    
    memset(dp, -1, sizeof(dp));
    int ans = solve(sccId[S], sccId[T]);
    if(visited[sccId[T]]) cout << ans;
    else cout << 0;

}