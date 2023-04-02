#include <bits/stdc++.h>

using namespace std;
int dis[2004];
int sccId[2004];
stack<int> st;
int disCnt = 0, sccCnt = 1;
vector<vector<int>> adj;

int tarjan(int cur) {
    dis[cur] = ++disCnt;
    int ret = dis[cur];
    st.push(cur);

    for (int next : adj[cur]) {
        if (!dis[next]) ret = min(ret, tarjan(next));
        if (!sccId[next]) ret = min(ret, dis[next]);
    }

    if (ret == dis[cur]) {
        while (1) {
            int t = st.top();
            st.pop();
            sccId[t] = sccCnt;
            if (t == cur) break;
        }
        ++sccCnt;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    while (cin >> n >> m) {
        adj.assign(2 * n + 2, vector<int>());
        memset(dis, 0, sizeof(dis));
        memset(sccId, 0, sizeof(sccId));
        disCnt = 0;
        sccCnt = 1;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            int notA, notB;
            if (a < 0) {
                a = (-a) * 2 + 1;
                notA = a - 1;
            } else {
                a = a * 2;
                notA = a + 1;
            }
            if (b < 0) {
                b = (-b) * 2 + 1;
                notB = b - 1;
            } else {
                b = b * 2;
                notB = b + 1;
            }
            adj[notB].push_back(a);
            adj[notA].push_back(b);
        }

        adj[3].push_back(2);

        for (int i = 2; i <= 2 * n + 1; i++) {
            if (dis[i]) continue;
            tarjan(i);
        }

        bool cr = false;
        for (int i = 2; i <= 2 * n; i += 2) {
            if (sccId[i] == sccId[i + 1]) {
                cr = true;
                break;
            }
        }

        if (cr) {
            cout << "no"
                 << "\n";
        } else {
            cout << "yes"
                 << "\n";
        }
    }
}