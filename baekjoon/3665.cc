#include <bits/stdc++.h>

using namespace std;
int N, M;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> arr;
        vector<int> added(n+1, 0);
        vector<int> level(n+1, 0);
        vector<vector<int>> adj(n+1);
        int l = 1;
        for(int i=0; i<n; i++) {
            int t; cin >> t;
            arr.push_back(t);
            level[t] = l++;
        }

        int m;
        cin >> m;
        for(int i=0; i<m; i++) {
            int a, b;
            cin >> a >> b;
            added[a] = 1;
            added[b] = 1;
            if(level[a] > level[b]) {
                adj[b].push_back(a);
            }
            else {
                adj[a].push_back(b);
            }
        }

        for(int i=0; i<n; i++) {
            if(added[i]) continue;
            
        }
    }
}