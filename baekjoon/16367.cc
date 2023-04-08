#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj;
int dis[10004] = {0, };
int sccId[10004] = {0, };
int disCnt = 0, sccCnt = 1;
int k, n;
stack<int> st;

int tarjan(int cur) {
    dis[cur] = ++disCnt;
    int ret = dis[cur];
    st.push(cur);
    for(int next : adj[cur]) {
        if(!dis[next]) ret = min(ret, tarjan(next));
        else if(!sccId[next]) ret = min(ret, dis[next]);
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
    cin >> k >> n;
    adj.resize(10004);
    for(int i=0; i<n; i++) {
        char f_a, f_b, f_c;
        int a, b, c;
        cin >> a >> f_a >> b >> f_b >> c >> f_c;
        a = f_a == 'R' ? a : -a;
        b = f_b == 'R' ? b : -b;
        c = f_c == 'R' ? c : -c;
        adj[a > 0 ? k + abs(a) : abs(a)].push_back(b > 0 ? b : k + abs(b));
        adj[b > 0 ? k + abs(b) : abs(b)].push_back(a > 0 ? a : k + abs(a));
        adj[c > 0 ? k + abs(c) : abs(c)].push_back(b > 0 ? b : k + abs(b));
        adj[b > 0 ? k + abs(b) : abs(b)].push_back(c > 0 ? c : k + abs(c));
        adj[a > 0 ? k + abs(a) : abs(a)].push_back(c > 0 ? c : k + abs(c));
        adj[c > 0 ? k + abs(c) : abs(c)].push_back(a > 0 ? a : k + abs(a));
    }

    for(int i=1; i<=2*k; i++) {
        if(dis[i]) continue;
        tarjan(i);
    }

    for(int i=1; i<=k; i++) {
        if(sccId[i] == sccId[k+i]) {
            cout << -1;
            return 0;
        }
    }

    vector<pair<int ,int>> cscc;
    for(int i=1; i<=k*2; i++) {
        cscc.push_back({-sccId[i], i});
    }
    sort(cscc.begin(), cscc.end());

    int result[10004];
    memset(result, -1, sizeof(result));
    for(pair<int, int> t : cscc) {
        int x = t.second;
        if(result[x] == -1) {
            result[x] = 0;
            result[x<=k ? k + x : x - k] = 1;
        }
    }

    for(int i=1; i<=k; i++) {
        if(result[i]) cout << 'R';
        else cout << 'B';
    }


}