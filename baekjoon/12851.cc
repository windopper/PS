#include <bits/stdc++.h>

using namespace std;

int N, K;
void solve(int x) {
    int cnt = 0;
    int fastest = -1;
    queue<pair<int ,int>> q;
    q.push({x, 0});

    vector<int> dist(200001, 0);
    for(int i=0; i<200002; i++) dist[i] = 2000000;

    while(!q.empty()) {
        pair<int ,int> cur = q.front();
        q.pop();
        int loc = cur.first;
        int sec = cur.second;
        if(loc == K) {
            if(cnt > 0 && fastest != sec) {
                break;
            }
            if(cnt == 0) {
                fastest = sec;
            }
            ++cnt;
        }
        
        if(dist[loc] < sec) continue;
        dist[loc] = sec;

        if(loc > K) {
            q.push({loc -1, sec + 1});
        }
        else if(loc > 0) {
            q.push({loc * 2, sec + 1});
            q.push({loc - 1, sec + 1});
            q.push({loc + 1, sec + 1});
        }
        else if(loc == 0) {
            q.push({loc + 1, sec + 1});
        }
    }
    std::cout << fastest << "\n" << cnt;
    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); std::cout.tie(0);
    cin >> N >> K;
    solve(N);
}