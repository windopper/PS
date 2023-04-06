#include <bits/stdc++.h>

using namespace std;
int N, Q;
vector<vector<int>> adj;
vector<pair<int, int>> edges;
int csum[2223][2223];

int parent[2223];
int level[2223];

void dfs(int cur, int post) {
    for(int next : adj[cur]) {
        if(post == next) continue;
        parent[next] = cur;
        level[next] = level[cur] + 1;
        dfs(next, cur);
    }
}

void lca(int a, int b) {
    int originalA = a;
    int originalB = b;
    if(level[a] > level[b]) swap(a, b);
    int diff = level[b] - level[a];
    while(diff != 0) {
        if(b < parent[b]) csum[b][parent[b]]++;
        else csum[parent[b]][b]++;
        b = parent[b];
        --diff;
    }

    while(a != b) {
        if(b < parent[b]) csum[b][parent[b]]++;
        else csum[parent[b]][b]++;

        if(a < parent[a]) csum[a][parent[a]]++;
        else csum[parent[a]][a]++;
        b = parent[b];
        a = parent[a];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> Q;
    adj.resize(N+1);
    memset(csum, 0, sizeof(csum));
    for(int i=0; i<N-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        if(a>b) swap(a, b);
        edges.push_back({a, b});
    }

    level[1] = 1;
    parent[1] = 0;
    dfs(1, 1);

    for(int i=0; i<Q; i++) {
        int a, b;
        cin >> a >> b;
        lca(a, b);
    }

    vector<vector<int>> result;
    for(pair<int, int> e : edges) {
        result.push_back({csum[e.first][e.second], e.first, e.second});
    }

    sort(result.begin(), result.end(), greater<>());
    cout << result[0][1] << " " << result[0][2] << " " << result[0][0];


}