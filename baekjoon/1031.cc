#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj;
vector<vector<int>> flow;
vector<vector<int>> capacity;
vector<int> arrN;
vector<int> arrM;
const int MAXN = 103;
const int INF = 987754321;
int source = 101, sink = 102;
int N, M;

void flowSwap(int j, int i) {
    setFlowAndCapacity(j, i, 0);
    vector<int> parent(MAXN, -1);
    queue<int> q;
    q.push(source);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int next : adj[cur]) {
            if (capacity[cur][next] - flow[cur][next] > 0 && parent[next] == -1) {
                parent[next] = cur;
                q.push(next);
            }
        }
    }
    int amount = INF;
    for (int p = sink; p != source; p = parent[p]) {
        amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
    }
    for (int p = sink; p != source; p = parent[p]) {
        flow[parent[p]][p] += amount;
        flow[p][parent[p]] -= amount;
    }
}

void setFlowAndCapacity(int j, int i, int val) {
    capacity[source][i] = val;
    capacity[j][i] = val;
    capacity[i][sink] = val;
    flow[source][i] = val;
    flow[j][i] = val;
    flow[i][sink] = val;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    adj.resize(MAXN);
    flow.assign(MAXN, vector<int>(MAXN, 0));
    capacity.assign(MAXN, vector<int>(MAXN, 0));
    for (int i = N; i >= 1; i--) {
        for (int j = 50 + M; j >= 51; j--) {
            adj[i].push_back(j);
            adj[j].push_back(i);
            capacity[i][j] = 1;
        }
    }
    for (int i = 1; i <= N; i++) {
        int t;
        cin >> t;
        arrN.push_back(t);
        adj[source].push_back(i);
        adj[i].push_back(source);
        capacity[source][i] = t;
    }

    for (int i = 51; i <= 50 + M; i++) {
        int t;
        cin >> t;
        arrM.push_back(t);
        adj[i].push_back(sink);
        adj[sink].push_back(i);
        capacity[i][sink] = t;
    }

    flow.assign(MAXN, vector<int>(MAXN, 0));
    while (1) {
        vector<int> parent(MAXN, -1);
        queue<int> q;
        q.push(source);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int next : adj[cur]) {
                if (capacity[cur][next] - flow[cur][next] > 0 && parent[next] == -1) {
                    parent[next] = cur;
                    q.push(next);
                }
            }
        }
        if (parent[sink] == -1) break;
        int amount = INF;
        for (int p = sink; p != source; p = parent[p]) {
            amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
        }
        for (int p = sink; p != source; p = parent[p]) {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
    }

    bool check = true;
    vector<int> cntN(N, 0);
    vector<int> cntM(M, 0);
    for (int ii = 1; ii <= N; ii++) {
        for (int jj = 51; jj <= 50 + M; jj++) {
            if (flow[ii][jj] == 1) {
                cntN[ii - 1]++;
                cntM[jj - 51]++;
            }
        }
    }

    for (int k = 0; k < N; k++) {
        if (cntN[k] != arrN[k]) {
            check = false;
            break;
        }
    }

    for (int k = 0; k < M; k++) {
        if (cntM[k] != arrM[k]) {
            check = false;
            break;
        }
    }

    if (check) {
        for (int m = 1; m <= N; m++) {
            for (int n = 51; n <= 50 + M; n++) {
                cout << flow[m][n];
            }
            cout << '\n';
        }
        return 0;
    }

    cout << -1;
    return 0;
}