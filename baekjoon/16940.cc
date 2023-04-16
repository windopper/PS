#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<set<int>> adj(N+1);
    for(int i=0; i<N-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
    }
    queue<int> q;

    int cur = -1;
    int cnt = -1;
    bool correct = true;
    for(int i=0; i<N; i++) {
        int t;
        cin >> t;
        if(!correct) continue;
        if(i == 0) {
            if(t != 1) {
                cout << 0;
                correct = false;
                continue;
            }
            cur = t;
            cnt = adj[t].size();
        }
        else {
            if(cnt > 0) {
                if(adj[cur].find(t) != adj[cur].end()) {
                    q.push(t);
                    --cnt;
                }
                else {
                    cout << 0;
                    correct = false;
                }

                if(cnt == 0) {
                    cur = q.front();
                    q.pop();
                    cnt = adj[cur].size();
                }
            }
            else {
                cout << 0;
                correct = false;
            }
        }
    }

    if(correct) cout << 1;
}