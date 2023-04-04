#include <bits/stdc++.h>

using namespace std;
int parent[200001];
int p[200001];

int find(int i) {
    if(i == parent[i] ) return i;
    return parent[i] = find(parent[i]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, Q;
    cin >> N >> Q;
    for(int i=1; i<=N; i++) parent[i] = i;
    for(int i=1; i<N; i++) {
        int t;
        cin >> t;
        p[i+1] = t;
    }
    vector<vector<int>> queries;
    for(int i=0; i<Q; i++) {
        int x, b;
        cin >> x >> b;
        if(x == 0) {
            queries.push_back({x, b});
        }
        else {
            int d;
            cin >> d;
            queries.push_back({x, b, d});
        }
    }

    reverse(queries.begin(), queries.end());

    vector<int> ans;
    for(int i=0; i<Q; i++) {
        if(queries[i][0] == 0) {
            int node = queries[i][1];
            int a = find(node);
            int b = find(p[node]);
            if(a != b) {
                parent[a] = b;
            }
        }
        else {
            int node = queries[i][1];
            int nxt = queries[i][2];
            if(find(node) == find(nxt)) {
                ans.push_back(1);
            }
            else ans.push_back(0);
        }
    }

    for(int i=ans.size()-1; i>=0; --i) {
        if(ans[i]) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }

}