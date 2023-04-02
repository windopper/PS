#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj;
int dis[20004] = {0, };
int sccId[20004];
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
        while(1) {
            int t= st.top();
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
    int N, M;
    cin >> N >> M;
    adj.resize(M*2+4, vector<int>());
    for(int i=0; i<N; i++) {
        int x, y;
        cin >> x >> y;
        int notX, notY;
        if(x<0) {
            x = (-x)*2+1;
            notX = x-1;
        }
        else {
            x = x*2;
            notX = x+1;
        }

        if(y<0) {
            y = (-y)*2+1;
            notY = y-1;
        }
        else {
            y = y*2;
            notY = y+1;
        }

        adj[notY].push_back(x);
        adj[notX].push_back(y);
    }

    for(int i=2; i<=2*M+1; i++) {
        if(dis[i]) continue;
        tarjan(i);
    }

    bool alive = true;
    for(int i=2; i<=2*M; i+=2) {
        if(sccId[i] == sccId[i+1]) {
            alive = false;
            break;
        }
    }

    if(alive) {
        cout << "^_^";
    }
    else {
        cout << "OTL";
    }
}