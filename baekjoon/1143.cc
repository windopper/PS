#include <bits/stdc++.h>
#include <limits>

using namespace std;
int N;
int costs[51];
vector<vector<int>> edges;
vector<vector<int>> sccs;
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
        vector<int> cycle;
        while(1) {
            int t = st.top(); st.pop();
            sccId[t] = sccCnt;
            cycle.push_back(t);
            if(t == cur) break;
        }
        sccs.push_back(cycle);
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
    int cnt = 0;

    for(int i=1; i<sccCnt; i++) {
        if(indegree[i] == 0) {
            int minCost = numeric_limits<int>::max();
            int minNode = -1;
            for(auto node : sccs[i-1]) {
                if(minCost > costs[node]) {
                    minCost = costs[node];
                    minNode = node;
                }
            }
            for(auto node : sccs[i-1]) {
                if(minNode == node) continue;
                remainMinPrice.push_back(costs[node]);
            }
            ans += minCost;
            ++cnt;
        }
        else {
            for(auto node : sccs[i-1]) {
                remainMinPrice.push_back(costs[node]);
            }
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