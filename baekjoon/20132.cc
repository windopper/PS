#include <bits/stdc++.h>
#include <limits>

using namespace std;
int N, M;

struct Edge {
    int u;
    int v;
    long long w;
    Edge(int _u, int _v, long long _w): u(_u), v(_v), w(_w){}
};

vector<Edge> edges;
vector<Edge> sorted;
vector<vector<pair<int, long long>>> mst;
int parent[18][100001];
int depth[100001];
long long maxEvenCost[18][100001];
long long maxOddCost[18][100001];

int unionParent[100001];
long long mstCost = 0;
int mstCnt = 0;

bool compare(Edge &a, Edge &b) {
    return a.w < b.w;
}

int find(int v) {
    if(v == unionParent[v]) return v;
    return unionParent[v] = find(unionParent[v]);
}

void getMst() {
    for(int i=1; i<N+1; i++) unionParent[i] = i;
    for(Edge edge : sorted) {
        int fu = find(edge.u);
        int fv = find(edge.v);
        if(fu != fv) {
            if(fu > fv) swap(fu, fv);
            unionParent[fv] = fu;
            mst[edge.u].push_back({edge.v, edge.w});
            mst[edge.v].push_back({edge.u, edge.w});
            mstCost += edge.w;
            ++mstCnt;
        }

        if(mstCnt == N-1) break;
    }
}

void dfs(int cur, int post) {
    for(int i=1; i<18; i++) {
        parent[i][cur] = parent[i-1][parent[i-1][cur]];
        maxOddCost[i][cur] = max(maxOddCost[i-1][cur], maxOddCost[i-1][parent[i-1][cur]]);
        maxEvenCost[i][cur] = max(maxEvenCost[i-1][cur], maxEvenCost[i-1][parent[i-1][cur]]);
    }

    for(int i=0; i<mst[cur].size(); i++) {
        int next = mst[cur][i].first;
        long long nextCost = mst[cur][i].second;
        if(next == post) continue;
        parent[0][next] = cur;
        depth[next] = depth[cur] + 1;
        if(nextCost % 2 == 0) {
            maxEvenCost[0][next] = nextCost;
        }
        else {
            maxOddCost[0][next] = nextCost;
        }
        dfs(next, cur);
    }
}

pair<long long, long long> lca(int a, int b, long long w) {
    long long ret1 = 0;
    long long ret2 = 0;
    if(depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];
    for(int i=0; diff != 0; i++) {
        if(diff % 2 == 1) {
            ret1 = max(ret1, maxOddCost[i][a]);
            ret2 = max(ret2, maxEvenCost[i][a]);
            a = parent[i][a];
        }
        diff /= 2;
    }

    if(a != b) {
        for(int i=17; i>=0; --i) {
            if(parent[i][a] != 0 && parent[i][a] != parent[i][b]) {
                ret1 = max(ret1, maxOddCost[i][a]);
                ret1 = max(ret1, maxOddCost[i][b]);
                ret2 = max(ret2, maxEvenCost[i][a]);
                ret2 = max(ret2, maxEvenCost[i][b]);
                a = parent[i][a];
                b = parent[i][b];
            }
        }

        ret1 = max(ret1, maxOddCost[0][a]);
        ret1 = max(ret1, maxOddCost[0][b]);
        ret2 = max(ret2, maxEvenCost[0][a]);
        ret2 = max(ret2, maxEvenCost[0][b]);
    }
    return {mstCost - ret1 + w, mstCost - ret2 + w};
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    mst.resize(N+1);
    for(int i=0; i<M; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
        sorted.push_back(Edge(u, v, w));
    }
    sort(sorted.begin(), sorted.end(), compare);

    getMst();

    parent[0][1] = 0;
    depth[1] = 1;
    dfs(1, 1);

    long long odd = numeric_limits<long long>::max();
    long long even = numeric_limits<long long>::max();
    if(mstCost % 2 == 0) even = mstCost;
    else odd = mstCost;

    for(Edge edge : edges) {
        pair<long long, long long> ret = lca(edge.v, edge.u, edge.w);
        if(ret.first - edge.w != mstCost) {
            if(ret.first % 2 == 0) {
                even = min(even, ret.first);
            }
            else {
                odd = min(odd, ret.first);
            }
        }
        if(ret.second - edge.w != mstCost) {
            if(ret.second % 2 == 0) {
                even = min(even, ret.second);
            }
            else {
                odd = min(odd, ret.second);
            }
        }
    }

    if(odd == numeric_limits<long long>::max()) {
        cout << -1 << " ";
    }
    else cout << odd << " ";

    if(even == numeric_limits<long long>::max()) {
        cout << -1;
    }
    else cout << even;
}