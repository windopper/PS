#include <bits/stdc++.h>

using namespace std;
int T;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    for(; T>0; T--) {
        long long x, y;
        cin >> x >> y;
        deque<vector<long long>> dq;
        bool visited[numeric_limits<unsigned int>::max()] = {false, };
        dq.push_back({x, 0, 0});
        while(!dq.empty()) {
            long long loc = dq.front()[0];
            long long move = dq.front()[1];
            long long cnt = dq.front()[2];
            if(loc == y && move == 1) {
                cout << cnt;
                break;
            }
            for(int i=-1; i<=1; i++) {
                int nxt = loc + move + i;
                if(nxt < 0 || nxt > y) continue;
                if(!visited[nxt]) {
                    visited[nxt] = true;
                    dq.push_back({nxt, move + i, cnt + 1});
                }
            }
        }
    }
}