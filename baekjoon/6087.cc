#include <bits/stdc++.h>
#include <limits>

using namespace std;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int W, H;
vector<string> arr;
vector<pair<int, int>> lazer;
vector<vector<int>> visited;
vector<vector<int>> dist;


int bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    dist[y][x] = 0;
    visited[y][x] = 1;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            while(nx>=0 && nx<W && ny>=0 && ny<H) {
                if(arr[ny][nx] == '*') break;
                if(visited[ny][nx] == 0) {
                    visited[ny][nx] = 1;
                    dist[ny][nx] = dist[y][x] + 1;
                    q.push({nx, ny});
                }
                nx += dx[i];
                ny += dy[i]; 
            }
        }
    }
    return dist[lazer[1].second][lazer[1].first] - 1;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> W >> H;
    dist.resize(H, vector<int>(W, 0));
    visited.resize(H, vector<int>(W, 0));
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