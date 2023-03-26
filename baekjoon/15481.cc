#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int N, M;
vector<vector<ll>> edges;
vector<vector<ll>> sorted;
vector<vector<pair<ll, ll>>> graph;
vector<vector<pair<ll, ll>>> mst;
long long mstCost = 0;
int parent[18][200001];
int depth[200001];
long long maxCost[18][200001];

int unionParent[200001];

int find(int cur) {
    if(unionParent[cur] == cur) return cur;
    return unionParent[cur] = find(unionParent[cur]);
}

void getMst() {
    for(int i=1; i<N+1; i++) {
        unionParent[i] = i;
    }
    for(vector<ll> edge : sorted) {
        ll w = edge[0];
        int u = edge[1];
        int v = edge[2];
        int originalU = u;
        int originalV = v;
        u = find(u);
        v = find(v);
        if(u != v) {
            if(u > v) swap(u, v);
            unionParent[v] = u;
            mst[originalU].push_back({originalV, w});
            mst[originalV].push_back({originalU, w});
            mstCost += w;
        }
    }
}

void dfs(int cur, int post) {
    for(int i=1; i<18; i++) {
        parent[i][cur] = parent[i-1][parent[i-1][cur]];
        maxCost[i][cur] = max(maxCost[i-1][cur], maxCost[i-1][parent[i-1][cur]]);
    }

    for(int i=0; i<mst[cur].size(); i++) {
        int next = mst[cur][i].first;
        long long nextCost = mst[cur][i].second;
        if(next == post) continue;
        parent[0][next] = cur;
        depth[next] = depth[cur] + 1;
        maxCost[0][next] = nextCost;
        dfs(next, cur);
    }
}

long long lca(int a, int b, long long w) {

    long long ret = 0;

    if(depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];
    for(int i=0; diff != 0; i++) {
        if(diff % 2 == 1) {
            ret = max(ret, maxCost[i][a]);
            a = parent[i][a];
        }
        diff /= 2;
    }

    if(a != b) {
        for(int i=17; i>=0; --i) {
            if(parent[i][a] != 0 && parent[i][a] != parent[i][b]) {
                ret = max(ret, maxCost[i][a]);
                ret = max(ret, maxCost[i][b]);
                a = parent[i][a];
                b = parent[i][b];
            }
        }
        ret = max(ret, maxCost[0][a]);
        ret = max(ret, maxCost[0][b]);
    }

    return mstCost - ret + w;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    graph.resize(N+1);
    mst.resize(N+1);
    for(int i=0; i<M; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        edges.push_back({u, v, w});
        sorted.push_back({w, u, v});
    }
    sort(sorted.begin(), sorted.end());

    getMst();

    depth[1] = 1;
    parent[0][1] = 0;
    maxCost[0][1] = 0;
    dfs(1, 1);

    for(auto node : edges) {
        int u = node[0];
        int v = node[1];
        long long w = node[2];
        cout << lca(u, v, w) << "\n";
    }
}