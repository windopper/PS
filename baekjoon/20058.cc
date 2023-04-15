#include <bits/stdc++.h>

using namespace std;
int N, Q, W;
vector<vector<int>> arr;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void rotate(int x1, int y1, int x2, int y2) {
    vector<vector<int>> newArr(y2-y1+1, vector<int>(x2-x1+1));
    for(int i=0; i<=y2-y1; i++) {
        for(int j=0; j<=x2-x1; j++) {
            newArr[j][x2-x1-i] = arr[i+y1][j+x1];
        }
    }
    for(int i=0; i<=y2-y1; i++) {
        for(int j=0; j<=x2-x1; j++) {
            arr[i+y1][j+x1] = newArr[i][j];
        }
    }
}

void loop(int L) {
    int acc = (int)pow(2, L);
    for(int i=0; i<W; i+=acc) {
        for(int j=0; j<W; j+=acc) {
            rotate(j, i, j+acc-1, i+acc-1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> Q;
    W = pow(2, N);
    arr.resize(W, vector<int>(W));
    for(int i=0; i<W; i++) {
        for(int j=0; j<W; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<Q; i++) {
        int L;
        cin >> L;
        loop(L);

        vector<pair<int, int>> reduces;
        for(int i=0; i<W; i++) {
            for(int j=0; j<W; j++) {
                if(arr[i][j] == 0) continue;
                int iceCnt = 0;
                for(int k=0; k<4; k++) {
                    int nx = j + dx[k];
                    int ny = i + dy[k];
                    if(nx<0||nx>=W||ny<0||ny>=W) continue;
                    if(arr[ny][nx] > 0) ++iceCnt;
                }

                if(iceCnt < 3) reduces.push_back({j, i});
            }
        }

        for(pair<int, int> p : reduces) {
            arr[p.second][p.first]--;
        }
    }

    long long sum = 0;
    for(int i=0; i<W; i++) {
        for(int j=0; j<W; j++) {
            sum += (long long)arr[i][j];
        }
    }

    long long maxMungTangi = 0;
    vector<vector<int>> vis(W, vector<int>(W, 0));
    for(int i=0; i<W; i++) {
        for(int j=0; j<W; j++) {
            if(vis[i][j]) continue;
            if(arr[i][j] == 0) continue;
            queue<pair<int ,int>> q;
            q.push({j, i});
            vis[i][j] = 1;
            long long mungTangi = 0;
            while(!q.empty()) {
                pair<int, int> cur = q.front();
                int x = cur.first;
                int y = cur.second;
                mungTangi++;
                q.pop();
                for(int k=0; k<4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(nx<0||nx>=W||ny<0||ny>=W) continue;
                    if(arr[ny][nx] == 0) continue;
                    if(vis[ny][nx]) continue;
                    vis[ny][nx] = 1;
                    q.push({nx, ny});
                }
            }

            maxMungTangi = max(maxMungTangi, mungTangi);
        }
    }

    cout << sum << "\n" << maxMungTangi;
}