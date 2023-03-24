#include <bits/stdc++.h>

using namespace std;
int V, E;
vector<vector<int>> edges;
int dis[100001];
vector<pair<int, int>> isCut;
int num = 0;

int dfs(int here, int parent) {
    dis[here] = ++num;
    int ret = dis[here];

    for(int i=0; i<edges[here].size(); i++) {
        int next = edges[here][i];

        if(next == parent) continue;

        if(dis[next]) {
            ret = min(ret, dis[next]);
            continue;
        }

        int prev = dfs(next, here);

        if(prev > dis[here])
            isCut.push_back({min(next, here), max(next, here)});

        ret = min(ret, prev);
    }

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
        dfs(i, i);
    }

    cout << isCut.size() << "\n";
    sort(isCut.begin(), isCut.end());
    for(int i=0; i<isCut.size(); i++) {
        cout << isCut[i].first << " " << isCut[i].second << "\n";
    }
}