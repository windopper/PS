#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj;
int dis[2002];
int sccId[2002];
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
    int N, M;
    cin >> N >> M;
    adj.resize(2*N+2);
    for(int i=0; i<M; i++) {
        int a, b;
        char c, d;
        cin >> a >> c >> b >> d;
        int notA, notB;
        if(c == 'Y') {
            a = 2*a;
            notA = a+1;
        }
        else {
            a = 2*a+1;
            notA = a-1;
        }

        if(d == 'Y') {
            b = 2*b;
            notB = b+1;
        }
        else {
            b = 2*b+1;
            notB = b-1;
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
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    int outdegree[2*N+2];
    memset(outdegree, 0, sizeof(outdegree));

    for(int i=2; i<=2*N+1; i++) {
        for(int next : adj[i]) {
            if(sccId[i] != sccId[next]) {
                ++outdegree[sccId[i]];
            }
        }
    }


    vector<pair<int, int>> order;
    for(int i=2; i<=N*2+1; i++) {
        order.push_back({-sccId[i], i});
    }

    sort(order.begin(), order.end());

    vector<int> tf1(N+2, -1);
    for(int i=0; i<2*N; i++) {
        //cout << order[i].second << " " << outdegree[sccId[order[i].second]] << "\n";
        if(outdegree[sccId[order[i].second/2]] != 0) {
            tf1[order[i].second/2] = 2;
            continue;
        }
        int vertex = order[i].second;
        int v = vertex / 2;
        bool isTrue = vertex % 2 != 0;
        if(tf1[v] == -1) {
            tf1[v] = isTrue;
        }
    }

    for(int i=1; i<=N; i++) {
        if(tf1[i] == 1) {
            cout << "Y";
        }
        else if(tf1[i] == 0) cout << "N";
        else if(tf1[i] == 2) cout << "?";
    }
}