#include <bits/stdc++.h>

using namespace std;
typedef pair<int ,int> pii;
int N, M;
vector<vector<int>> arr;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    arr.resize(N, vector<int>(N));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }

    int ret = 0;
    while(1) {
        vector<pii> blocks;
        int maxRainbow = -1;
        int maxSize = -1;
        int maxX = -1;
        int maxY = -1;
        vector<vector<int>> vis(N, vector<int>(N, 0));
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(arr[i][j] <= 0) continue;
                if(vis[i][j]) continue;
                int curRainbow = 0;
                int curColor = arr[i][j];
                int curSize = 0;
                vector<pii> curblocks;
                queue<pii> q;
                q.push({j, i});
                curblocks.push_back({j, i});
                vis[i][j] = 1;
                while(!q.empty()) {
                    pii cur = q.front();
                    int x = cur.first;
                    int y = cur.second;
                    q.pop();
                    if(arr[y][x] == 0) ++curRainbow;
                    ++curSize;
                    for(int k=0; k<4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(nx<0||nx>=N||ny<0||ny>=N) continue;
                        if(vis[ny][nx]) continue;
                        if(arr[ny][nx] <= -1 || (arr[ny][nx] >= 1 && arr[ny][nx] != curColor)) continue;
                        vis[ny][nx] = 1;
                        q.push({nx, ny});
                        curblocks.push_back({nx, ny});
                    }
                }
                
                sort(curblocks.begin(), curblocks.end(), [](pii& a, pii & b) {
                    if(a.second != b.second) return a.second < b.second;
                    return a.first < b.first;
                }); 

                int si = -1;
                int sj = -1;

                for(pii p : curblocks) {
                    if(arr[p.second][p.first] == 0) vis[p.second][p.first] = 0;
                    else if(si == -1 && sj == -1) {
                        si = p.second;
                        sj = p.first;
                    }
                }
                
                if(maxSize < curSize) {
                    maxSize = curSize;
                    maxRainbow = curRainbow;
                    maxY = si;
                    maxX = sj;
                    blocks = curblocks;
                }
                else if(maxSize == curSize && maxRainbow < curRainbow) {
                    maxRainbow = curRainbow;
                    maxY = si;
                    maxX = sj;
                    blocks = curblocks;
                }
                else if(maxSize == curSize && maxRainbow == curRainbow && maxY < si) {
                    maxY = si;
                    maxX = sj;
                    blocks = curblocks;
                }
                else if(maxSize == curSize && maxRainbow == curRainbow && maxY == si && maxX < sj) {
                    maxX = sj;
                    blocks = curblocks;
                }
            }
        }

        if(maxSize < 2) break;

        ret += (maxSize * maxSize);

        for(pii p : blocks) {
            int x = p.first;
            int y = p.second;
            arr[y][x] = -2;
        }

        for(int j=0; j<N; j++) {
            for(int i=N-2; i>=0; i--) {
                if(arr[i][j] == -1 || arr[i][j] == -2) continue;
                int k = i+1;
                while(k <= N-1 && arr[k][j] == -2) {
                    ++k;
                }
                if(k-1 != i) {
                    arr[k-1][j] = arr[i][j];
                    arr[i][j] = -2;
                }
            }
        }

        vector<vector<int>> rotate(N, vector<int>(N));
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                rotate[N-1-j][i] = arr[i][j];
            }
        }

        arr = rotate;

        for(int j=0; j<N; j++) {
            for(int i=N-2; i>=0; i--) {
                if(arr[i][j] == -1 || arr[i][j] == -2) continue;
                int k = i+1;
                while(k <= N-1 && arr[k][j] == -2) {
                    ++k;
                }
                if(k-1 != i) {
                    arr[k-1][j] = arr[i][j];
                    arr[i][j] = -2;
                }
            }
        }
    }
    cout << ret;
}