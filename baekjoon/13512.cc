#include <bits/stdc++.h>

/*
세그먼트 트리를 이용한 K번째 수 구하기 + HLD

*/

using namespace std;
int tree[1<<18] = {0, };
int base = 1<<17;
vector<vector<int>> adj;

const int INF = 987654321;
vector<int> g[100001];
int sz[100001], dep[100001] = {0, }, in[100001], top[100001], parent[100001];
int inToN[100001];
int seq = 0;
vector<int> vis(100001, 0);
int N;

// 단방향 그래프 생성
void createGraph(int cur = 1) {
    vis[cur] = 1;
    for(auto next : adj[cur]) {
        if(vis[next]) continue;
        vis[next] = 1;
        g[cur].push_back(next);
        createGraph(next);
    }
}

// 그래프 체이닝
void hld(int cur = 1) {
    sz[cur] = 1;
    for(int& next : g[cur]) {
        dep[next] = dep[cur] + 1;
        parent[next] = cur;
        hld(next);
        sz[cur] += sz[next];
        if(sz[next] > sz[g[cur][0]]) swap(next, g[cur][0]);
    }
}

void dfsorder(int cur = 1) {
    inToN[++seq] = cur;
    in[cur] = seq;
    for(int& next : g[cur]) {
        top[next] = next == g[cur][0] ? top[cur] : next;
        dfsorder(next);
    }
}


void segUpdate(int x) {
    x |= base;
    tree[x] = 1 - tree[x];
    while(x >>= 1) {
        tree[x] = tree[x<<1] + tree[x<<1 | 1];
    }
}

int segSum(int a, int b) {
    a |= base;
    b |= base;
    int ret = 0;
    while(a <= b) {
        if(a & 1) ret += tree[a++];
        if(~b & 1) ret += tree[b--];
        a >>= 1, b >>= 1;
    }
    return ret;
}

int segQuery(int a, int b) {
    if(segSum(a, b) == 0) return -1;
    int ret = -1;
    while(a <= b) {
        int m = (a+b) >> 1;
        if(segSum(a, m)) {
            ret = m;
            b = m-1;
        }
        else a = m + 1;
    }
    return ret;
}

void update(int i) {
    segUpdate(in[i]);
}

int query(int v) {
    if(tree[1 | base] == 1) return 1;
    int ret = -1;
    int a = 1;
    int b = v;
    while(top[a] ^ top[b]) {
        if(dep[top[a]] < dep[top[b]]) swap(a, b);
        int st = top[a];
        int cur = segQuery(in[st], in[a]);
        if(cur > 0) ret = cur;
        a = parent[st];
    }
    if(dep[a] > dep[b]) swap(a, b);
    int cur = segQuery(in[a], in[b]);
    if(cur > 0) ret = cur;
    return ret > 0 ? inToN[ret] : -1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    adj.resize(N+1);
    for(int i=0; i<N-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    createGraph();
    hld();
    dfsorder();

    int M;
    cin >> M;
    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        // 1 i update
        // 2 v query
        if(a == 1) {
            update(b);
        }
        else {
            cout << query(b);
            cout << '\n';
        }
    }
}