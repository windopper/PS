#include <bits/stdc++.h>

using namespace std;

int tree[1 << 18] = {0, };
int base = 1 << 17;

int group[30001];
int dep[30001], in[30001], sz[30001], par[30001], top[30001];
vector<vector<int>> adj(30001);
vector<bool> bridgeCreated(30001, false);
vector<int> g[30001];
int pv = 0;

int find(int x) {
    if(x == group[x]) return x;
    return group[x] = find(group[x]);
}

void merge(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if(pa != pb) {
        if(pa > pb) swap(pa, pb);
        group[pb] = pa;
    }
}

vector<bool> vis(30001, false);

void createBridge(int cur) {
    vis[cur] = 1;
    for(int next : adj[cur]) {
        if(vis[next]) continue;
        vis[next] = 1;
        g[cur].push_back(next);
        createBridge(next);
    }
}

void hld(int cur) {
    vis[cur] = 1;
    sz[cur] = 1;
    for(auto &i : g[cur]) {
        if(vis[i]) continue;
        vis[i] = 1;
        dep[i] = dep[cur] + 1;
        par[i] = cur;
        hld(i);
        sz[cur] += sz[i];
        if(sz[i] > sz[g[cur][0]]) swap(i, g[cur][0]);
    }
}

void dfsOrdering(int cur) {
    vis[cur] = 1;
    in[cur] = pv++;
    for(int next : g[cur]) {
        if(vis[next]) continue;
        vis[next] = 1;
        top[next] = next == g[cur][0] ? top[cur] : next;
        dfsOrdering(next);
    }
}

vector<int> arr(30001, 0);

void segUpdate(int x, int v) {
    x |= base;
    tree[x] = v;
    while(x >>= 1) {
        tree[x] = tree[x << 1] + tree[x << 1 | 1];
    }
}

int segQuery(int l, int r) {
    l |= base;
    r |= base;  
    int ret = 0;
    while(l <= r) {
        if(l & 1) ret += tree[l++];
        if(~r & 1) ret += tree[r--];
        l >>= 1, r >>= 1;
    }
    return ret;
}

void update(int x, int v) {
    segUpdate(in[x], v);
}

int query(int l, int r) {
    int ret = 0;
    while(top[l] ^ top[r]) {
        if(dep[top[l]] < dep[top[r]]) swap(l, r);
        int st = top[l];
        ret += segQuery(in[st], in[l]);
        l = par[st];
    }
    if(dep[l] > dep[r]) swap(l, r);
    ret += segQuery(in[l], in[r]);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> arr[i+1];
    }

    for(int i=1; i<=30000; i++) {
        group[i] = i;
    }

    int Q;
    cin >> Q;
    vector<pair<string, pair<int, int>>> queries;
    vector<string> reconstruct(Q, "");
    for(int i=0; i<Q; i++) {
        string s;
        int a, b;
        cin >> s >> a >> b;
        queries.push_back({s, {a, b}});
        int pa = find(a);
        int pb = find(b);
        if(s == "bridge") {
            adj[a].push_back(b);
            adj[b].push_back(a);
            if(pa == pb) {
                reconstruct[i] = "no";
            }
            else {
                merge(a, b);
                reconstruct[i] = "yes";
            }
        }
        else if(s == "excursion") {
            if(pa != pb) {
                reconstruct[i] = "impossible";
            }
        }
    }

    vis.assign(N+1, 0);
    for(int i=1; i<=N; i++) {
        if(vis[i]) continue;
        createBridge(i);
    }
    vis.assign(N+1, 0);
    for(int i=1; i<=N; i++) {
        if(vis[i]) continue;
        hld(i);
    }
    vis.assign(N+1, 0);
    for(int i=1; i<=N; i++) {
        if(vis[i]) continue;
        dfsOrdering(i);
    }

    for(int i=1; i<=N; i++) {
        update(i, arr[i]);
    }
    
    for(int i=0; i<Q; ++i) {
        pair<string, pair<int, int>> q = queries[i];
        string s = q.first;
        int a = q.second.first;
        int b = q.second.second;
        if(reconstruct[i] != "") {
            cout << reconstruct[i] << '\n';
            continue;
        }
        if(s == "penguins") {
            update(a, b);
        }
        else if(s == "excursion") {
            cout << query(a, b) << '\n';
        }
    }
}