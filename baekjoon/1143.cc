#include <bits/stdc++.h>

using namespace std;
int N;
int costs[51];
vector<vector<int>> edges;
vector<int> sccs;
int dis[51];
int sccId[51];
int indegree[51];
stack<int> st;
int n = 0, sccCnt = 1;

int tarjan(int cur) {
    dis[cur] = ++n;
    int ret = dis[cur];
    st.push(cur);
    for(auto next : edges[cur]) {
        if(!dis[next]) ret = min(ret, tarjan(next));
        if(!sccId[next]) ret = min(ret, dis[next]);
    }
    if(ret == dis[cur]) {
        int minCost = 1001;
        while(1) {
            int t = st.top(); st.pop();
            sccId[t] = sccCnt;
            minCost = min(minCost, costs[t]);
            if(t == cur) break;
        }
        sccs.push_back(minCost);
        ++sccCnt;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    edges.resize(N+1);
    for(int i=1; i<N+1; i++) cin >> costs[i];
    for(int i=1; i<N+1; i++) {
        string s;
        cin >> s;
        for(int j=1; j<N+1; j++) {
            if(s[j-1] == 'Y') {
                edges[i].push_back(j);
            }
        }
    }

    for(int i=1; i<N+1; i++) {
        if(dis[i]) continue;
        tarjan(i);
    }

    for(int i=1; i<N+1; i++) {
        for(auto next : edges[i]) {
            if(sccId[i] != sccId[next]) {
                ++indegree[sccId[next]];
            }
        }
    }

    double ans = 0;
    vector<int> remainMinPrice;
    double cnt = 0;

    for(int i=1; i<sccCnt; i++) {
        if(indegree[i] == 0) {
            ans += sccs[i-1];
            ++cnt;
        }
        else {
            remainMinPrice.push_back(sccs[i-1]);
        }
    }

    sort(remainMinPrice.begin(), remainMinPrice.end());

    for(auto remain : remainMinPrice) {
        if((ans / cnt) >= (double)remain) {
            ans += remain;
            ++cnt;
        }
    }
    cout << fixed;
    cout.precision(15);
    cout << (ans / cnt);

}