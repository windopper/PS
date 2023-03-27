#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<vector<int>> edges;
vector<vector<pair<int, int>>> mst;
int unionParent[100001];
int level[100001];
int parent[18][100001];
int maxCosts[18][100001];
int depth[100001];

int find(int v) {
    if(v == unionParent[v]) return v;
    return unionParent[v] = find(unionParent[v]);
}

void getMst() {
    for(int i=1; i<n+1; i++) {
        unionParent[i] = i;
    }
    for(int i=0; i<m; i++) {
        int cost = edges[i][0];
        int u = edges[i][1];
        int v = edges[i][2];
        int findU = find(u);
        int findV = find(v);
        if(findU != findV) {
            if(level[findU] == level[findV]) ++level[findV];
            if(level[findU] > level[findV]) swap(findV, findU);
            unionParent[findV] = findU;
            mst[u].push_back({v, cost});
            mst[v].push_back({u, cost});
        }
    }
}

void dfs(int cur, int post) {
    for(int i=1; i<18; i++) {
        parent[i][cur] = parent[i-1][parent[i-1][cur]];
        maxCosts[i][cur] = max(maxCosts[i-1][cur], maxCosts[i-1][parent[i-1][cur]]);
    }

    for(int i=0; i<mst[cur].size(); i++) {
        int next = mst[cur][i].first;
        int nextCost = mst[cur][i].second;
        if(next == post) continue;
        parent[0][next] = cur;
        depth[next] = depth[cur] + 1;
        maxCosts[0][next] = nextCost;
        dfs(next, cur);
    }
}

// O(n)
int querydfs(int cur, int lim, vector<int>& visited) {
    int ret = 0;
    for(int i=0; i<mst[cur].size(); i++) {
        int next = mst[cur][i].first;
        int nextCost = mst[cur][i].second;
        if(visited[next]) continue;
        visited[next] = 1;
        if(nextCost <= lim) {
            ret += querydfs(next, lim, visited) + 1;
        }
    }
    return ret;
}

// O(n + logm)
void query(int a, int b) {

    if(unionParent[a] != unionParent[b]) {
        cout << -1 << "\n";
        return;
    }

    int maxTemp = 0;
    int originA = a;
    int originB = b;

    if(depth[a] < depth[b]) swap(a, b);
    
    int diff = depth[a] - depth[b];
    for(int i=0; diff != 0; i++) {
        if(diff % 2 == 1) {
            maxTemp = max(maxTemp, maxCosts[i][a]);
            a = parent[i][a];
        }
        diff /= 2;
    }
    vector<int> visited = vector<int>(n+1, 0);
    int range = querydfs(originA, maxTemp, visited);

    cout << maxTemp << " " << range << "\n";
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    mst.resize(n+2);
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, a, b});
    }
    // O(mlogm)
    sort(edges.begin(), edges.end());

    // O(m)
    getMst();

    int curAnc = -1;
    // O(n)
    for(int i=1; i<n+1; i++) {
        if(curAnc == unionParent[i]) continue;
        curAnc = unionParent[i];
        maxCosts[0][i] = 0;
        parent[0][i] = 0;
        depth[i] = 1;
        dfs(i, i);
    }

    int Q;
    cin >> Q;

    // O(Q X (N + logN))
    for(int i=0; i<Q; i++) {
        int x, y;
        cin >> x >> y;
        query(x, y);
    }
}