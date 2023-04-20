#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj;
int candies[100001];
int parent[18][100001] = {0, };
int cp[6][18][100001] = {0, };
int depth[100001] = {0, };

void dfs(int cur, int post) {
    for(int i=1; i<18; i++) {
        parent[i][cur] = parent[i-1][parent[i-1][cur]];
        for(int j=1; j<=5; j++) {
            cp[j][i][cur] = cp[j][i-1][parent[i-1][cur]] + cp[j][i-1][parent[i-1][cur]];
        }
    }

    for(int next : adj[cur]) {
        if(next == post) continue;
        parent[0][next] = cur;
        for(int i=1; i<=5; i++) {
            cp[i][0][next] = (candies[cur] == i) + (candies[next] == i);
        }
        depth[next] = depth[cur] + 1;
        dfs(next, cur);
    }
}

void solve(int a, int b, int type) {
    if(depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];
    int candyCnt = 0;

    if(candies[a] == type || candies[b] == type) {
        cout << "PLAY";
        return;
    }

    for(int i=0; diff != 0; i++) {
        if(diff % 2 == 1) {
            candyCnt += cp[type][i][a];
            a = parent[i][a];
        }
        if (candyCnt > 0) {
            cout << "PLAY";
            return;
        }
        diff /= 2;
    }

    if(a != b) {
        for(int i=17; i>=0; --i) {
            if(parent[i][a] != parent[i][b] && parent[i][a] != 0) {
                candyCnt += cp[type][i][a] + cp[type][i][b];
                a = parent[i][a];
                b = parent[i][b];
                if (candyCnt > 0) {
                    cout << "PLAY";
                    return;
                }
            }
        }
        candyCnt += cp[type][0][a] + cp[type][0][b];
        a = parent[0][a];
        b = parent[0][b];
    }

    if (candyCnt > 0) {
        cout << "PLAY";
        return;
    }
    else if(candyCnt == 0) {
        cout << "CRY";
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    adj.resize(N+1);
    for(int i=1; i<N+1; i++) {
        int t; cin >> t;
        candies[i] = t;
    }
    for(int i=0; i<N-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[1] = 1;
    parent[0][1] = 0;
    dfs(1, 1);

    int M;
    cin >> M;
    int prev = -1;
    for(int i=0; i<M; i++) {
        int loc, type;
        cin >> loc >> type;

        if(i == 0) {
            for(int i=1; i<=N; i++) {
                if(candies[i] == type) {
                    prev = i;
                    break;
                }
            }
        }

        solve(loc, prev, type);
        cout << '\n';
        prev = loc;
    }
}