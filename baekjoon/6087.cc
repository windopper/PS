#include <bits/stdc++.h>
#include <limits>

using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int W, H;
vector<string> arr;
vector<pair<int, int>> lazer;

int bfs(int x, int y) {
    priority_queue<vector<int>> pq;
    // dist, x, y, mirror, post
    for(int i=0; i<4; i++) {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if(nx<0 || nx>=W || ny<0 || ny>=H) continue;
        if(arr[ny][nx] == '*') continue;
        pq.push({0, nx, ny, i});
    }
    while(!pq.empty()) {
        int mirror = -pq.top()[0];
        int x = pq.top()[1];
        int y = pq.top()[2];
        int post = pq.top()[3];
        pq.pop();
        if(x == lazer[1].first && y == lazer[1].second) {
            return mirror;
        }

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || nx>=W || ny<0 || ny>=H) continue;
            if(arr[ny][nx] == '*') continue;
            int nextMirror = mirror;
            if(post != i) ++nextMirror;
            pq.push({-nextMirror, nx, ny,  i});
        }
    }
    return 0;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> W >> H;
    for(int i=0; i<H; i++) {
        string s;
        cin >> s;
        arr.push_back(s);

        for(int j=0; j<W; j++) {
            if(s[j] == 'C') {
                lazer.push_back({j, i});
            }
        }
    }

    cout << bfs(lazer[0].first, lazer[0].second);
}