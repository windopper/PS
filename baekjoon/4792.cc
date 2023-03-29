#include <bits/stdc++.h>

using namespace std;
int n, m, k;
int parent[10001];
vector<pair<int, int>> blues;
vector<pair<int, int>> reds;

int find(int v) {
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}


int mst(vector<int>& edges) {
    for(int i=1; i<n+1; i++) {
        parent[i] = i;
    }

    int cnt = 0;

    for(int e : edges) {
        int a = find(blues[e].first);
        int b = find(blues[e].second);
        if(a != b) {
            if(a > b) swap(a, b);
            parent[b] = a;
            ++cnt;
        }
    }

    for(pair<int, int> red : reds) {
        int a = find(red.first);
        int b = find(red.second);
        if(a != b) {
            if(a > b) swap(a, b);
            parent[b] = a;
            ++cnt;
        }
    }

    if(cnt == n-1) return 1;
    else return 0;
}

int dfs(vector<int>& selected, int next, int remain) {
    if(blues.size() < k) return 0;
    if(remain == 0) {
        return mst(selected);
    }
    int ret = 0;
    for(int i=next; i<blues.size(); i++) {
        selected.push_back(i);
        ret = max(ret, dfs(selected, i+1, remain - 1));
        selected.pop_back();
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(1) {
        cin >> n >> m >> k;
        if(n == 0) break;

        memset(parent, 0, sizeof(parent));
        blues.clear();
        reds.clear();

        for(int i=0; i<m; i++) {
            char c; int f, t;
            cin >> c >> f >> t;
            if(c == 'B') blues.push_back({f, t});
            else reds.push_back({f, t});
        }
        vector<int> selected;
        cout << dfs(selected, 0, k) << "\n";
    }
    
}