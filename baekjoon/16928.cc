#include <bits/stdc++.h>

using namespace std;
int N, M;
vector<int> from;
vector<int> to;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        int x, y;
        cin >> x >> y;
        from.push_back(x);
        to.push_back(y);
    }
    for(int i=0; i<M; i++) {
        int u, v;
        cin >> u >> v;
        from.push_back(u);
        to.push_back(v);
    }
    
    deque<pair<int, int>> dq;
    int visited[101] = {0, };
    dq.push_back({1, 0});
    visited[1] = 1;
    while(!dq.empty()) {
        int location = dq.front().first;
        int cnt = dq.front().second;
        dq.pop_front();
        if(location == 100) {
            cout << cnt;
            break;
        }
        for(int i=1; i<7; i++) {
            int nxt = location + i;
            for(int i=0; i<from.size(); i++) {
                if(from[i] == nxt) {
                    nxt = to[i];
                    break;
                }
            }
            if(nxt > 100 || visited[nxt]) continue;
            visited[nxt] = 1;
            dq.push_back({nxt, cnt+1});
        }
    }
}   