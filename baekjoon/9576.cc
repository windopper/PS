#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(1001);
int bMatch[1001];
int dis[1001];

bool dfs(int cur) {
    if(dis[cur]) return false;
    dis[cur] = 1;
    for(int next : adj[cur]) {
        if(bMatch[next] == -1 || dfs(bMatch[next])) {
            bMatch[next] = cur;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for(; T>0; --T) {
        int N, M;
        cin >> N >> M;
        adj.assign(10001, vector<int>());
        for(int i=1; i<M+1; i++) {
            int a, b;
            cin >> a >> b;
            for(int j=a; j<=b; j++) {
                adj[i].push_back(j);
            }
        }

        memset(bMatch, -1, sizeof(bMatch));
        int cnt = 0;
        for(int i=1; i<=M; i++) {
            memset(dis, 0, sizeof(dis));
            if(dfs(i)) ++cnt;
        }

        cout << cnt << '\n';
    }


}