#include <bits/stdc++.h>
#include <limits>

using namespace std;
int N;
int costs[101];
int dis[101];
int sccId[101];
vector<vector<int>> edges;
stack<int> st;
int n = 0;
int ans = 0;

int tarjan(int cur) {
    dis[cur] = ++n;
    //sccId[cur] = 1;
    int ret = dis[cur];
    st.push(cur);
    for(int i=0; i<edges[cur].size(); i++) {
        int next = edges[cur][i];
        if(!dis[next]) {
            ret = min(ret, tarjan(next));
        }
        if(!sccId[next]) {
            ret = min(ret, dis[next]);
        }
    }

    if(ret == dis[cur]) {
        int cost = numeric_limits<int>::max();
        while(1) {
            int t = st.top();
            st.pop();
            sccId[t] = 1;
            cost = min(cost, costs[t]);
            if(t == cur) break;
        }
        ans += cost;
    }

    return ret;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=1; i<N+1; i++) {
        cin >> costs[i];
    }
    edges.resize(N+1);
    for(int i=1; i<N+1; i++) {
        string s;
        cin >> s;
        for(int j=1; j<N+1; j++) {
            if(s[j-1] - '0' == 1) {
                edges[i].push_back(j);
            }
        }
    }

    for(int i=1; i<N+1; i++) {
        if(dis[i]) continue;
        tarjan(i);
    }

    cout << ans;
}