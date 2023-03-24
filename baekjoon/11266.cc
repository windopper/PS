#include <bits/stdc++.h>

using namespace std;
int V, E;
vector<vector<int>> edges;
int dis[10001];
bool isCut[10001];
int num = 0;

int dfs(int cur, bool isRoot) {

    dis[cur] = ++num;
    int ret = dis[cur];
    int child = 0;

    for(int i=0; i<edges[cur].size(); i++) {
        int next = edges[cur][i];

        if(dis[next]) {
            ret = min(ret, dis[next]);
            continue;
        }

        ++child;
        int prev = dfs(next, false);

        if(!isRoot && prev >= dis[cur]) isCut[cur] = true;

        ret = min(ret, prev);
    }

    if(isRoot && child >= 2) isCut[cur] = true;

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> V >> E;
    edges.resize(V+1);
    for(int i=0; i<E; i++) {
        int A, B;
        cin >> A >> B;
        edges[A].push_back(B);
        edges[B].push_back(A);
    }

    for(int i=1; i<V+1; i++) {
        if(dis[i]) continue;
        dfs(i, true);
    }

    int ans = 0;
    for(int i=1; i<V+1; i++) {
        if(isCut[i]) ++ans;
    }

    cout << ans << "\n";
    for(int i=1; i<V+1; i++) {
        if(isCut[i]) cout << i << " ";
    }

}