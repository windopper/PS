#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
int N, M;
vector<vector<int>> adj;
vector<vector<int>> g;

int parent[100001];
int sz[100001];

bool compare(vi& a, vi& b) {
    return a[2] < b[2];
}

int find(int x) {
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    vector<pair<int ,int>> queries;
    for(int i=0; i<M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj.push_back({a, b, c});
    }
    int Q;
    cin >> Q;
    for(int i=0; i<Q; i++) {
        int x, y;
        cin >> x >> y;
        queries.push_back({x, y});
    }

    vector<int> l;
    vector<int> r;
    for(int i=0; i<Q; i++) {
        l.push_back(0);
        r.push_back(M);
    }

    sort(adj.begin(), adj.end(), compare);

    g.resize(M+1);
    vector<pair<int, int>> ans(Q);
    //pbs
    while(1) {
        g.clear();
        g.resize(M+1);
        bool flag = 0;
        for(int i=0; i<Q; i++) {
            if(l[i] != r[i]) {
                flag = 1;
                g[(l[i] + r[i]) >> 1].push_back(i);
            }
        }
        if(!flag) break;

        for(int i=0; i<100001; i++) {
            parent[i] = i;
            sz[i] = 1;
        }

        for(int i=0; i<M; i++) {
            int s = adj[i][0];
            int e = adj[i][1];
            int c = adj[i][2];
            
            int fs = find(s);
            int fe = find(e);
            if(fs != fe) {
                if(fs > fe) swap(fs, fe);
                parent[fe] = fs;
                sz[fs] += sz[fe];
            }

            for(auto next : g[i]) {
                int qa = find(queries[next].first);
                int qb = find(queries[next].second);
                if(qa == qb) {
                    r[next] = i;
                    ans[next].first = c;
                    ans[next].second = sz[find(qa)];
                }
                else {
                    l[next] = i+1;
                }
            }
        }
    }

    for(int i=0; i<Q; i++) {
        if(l[i] >= M) cout << "-1\n";
        else cout << ans[i].first << " " << ans[i].second << '\n';
    }
}